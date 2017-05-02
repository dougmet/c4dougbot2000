#' @useDynLib c4dougbot2000
#' @importFrom Rcpp sourceCpp
NULL


#' Check which positions will win
#'
#' @param board The board matrix
#' @param target Integer: What player id do you want.
#' @param n Integer:  Connect-n (usually 4)
#'
#' @return A vector of will win flags in each slot
#' @export
#'
#' @examples
#' set.seed(12)
#' x <- matrix(sample(1:2, size = 24, replace = TRUE), nrow = 4)
#' x <- apply(x, 2, function(y) {
#'   i=sample(4, size=1)-1
#'   y[1:i] <- NA
#'   y})
#'
check_win <- function(board, target = 1, n = 4) {

  ln <- get_lengths(board, target = target)

  top <- get_top(board)
  top[top<1] <- NA

  rows <- top + nrow(board)*(1:ncol(board) - 1)


  #win <- apply(ln[rows, ], 1, function(x) isTRUE(any(x >= n)))

  #win
}
