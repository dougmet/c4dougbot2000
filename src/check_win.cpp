#include <Rcpp.h>
using namespace Rcpp;


// [[Rcpp::export]]
IntegerMatrix get_nn(NumericMatrix board) {

  int n = board.nrow();
  int m = board.ncol();
  int sz = board.size();

  IntegerMatrix nn(sz, 8);

  for(int i=0; i<sz; i++) {
    for (int j=0; j<8; j++){

      int row = i % n;
      int col = i / n;

      nn(i, 0) = (row == n-1) ? -1:i + 1;
      nn(i, 1) = (row == 0) ? -1: i - 1;
      nn(i, 2) = (col == m-1) ? -1:i + n;
      nn(i, 3) = (col == 0) ? -1:i - n;

      nn(i, 4) = (row == n-1 || col == m-1) ? -1 : i + 1 + n;
      nn(i, 5) = (row == 0 || col == 0) ? -1 : i - 1 - n;
      nn(i, 6) = (row == 0 || col == m-1) ? -1 : i - 1 + n;
      nn(i, 7) = (row == n-1 || col == 0) ? -1 : i + 1 - n;
    }
  }

  return(nn);
}

// [[Rcpp::export]]
IntegerMatrix get_lengths(NumericMatrix board, int target) {

  IntegerMatrix nn = get_nn(board);

  int sz = board.size();

  IntegerMatrix ln(sz, 4);

  for (int i=0; i<sz; i++) {
    for (int j=0; j<4; j++) {
      ln(i, j) = 1;
      for (int k=0; k<2; k++) {
        int n = nn(i, 2*j + k);
        while(n > -1) {
          if(board[n] != target) break;
          ln(i, j) += 1;
          n = nn(n, 2*j + k);
        }
      }
    }
  }

  return(ln);
}

// [[Rcpp::export]]
IntegerVector get_top(NumericMatrix board) {

  int m = board.ncol();
  int n = board.nrow();
  IntegerVector x(m);

  for (int i=0; i<m; i++) {
    int j = 0; // because the board is upside down
    int k = i*n + j;
    while(j < m && NumericMatrix::is_na(board[k])) {
      k = i*n + j;
      j ++;
    }
    x(i) = j-1;
  }

  return(x);
}
