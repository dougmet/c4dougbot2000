// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// get_nn
IntegerMatrix get_nn(NumericMatrix board);
RcppExport SEXP c4dougbot2000_get_nn(SEXP boardSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericMatrix >::type board(boardSEXP);
    rcpp_result_gen = Rcpp::wrap(get_nn(board));
    return rcpp_result_gen;
END_RCPP
}
// get_lengths
IntegerMatrix get_lengths(NumericMatrix board, int target);
RcppExport SEXP c4dougbot2000_get_lengths(SEXP boardSEXP, SEXP targetSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericMatrix >::type board(boardSEXP);
    Rcpp::traits::input_parameter< int >::type target(targetSEXP);
    rcpp_result_gen = Rcpp::wrap(get_lengths(board, target));
    return rcpp_result_gen;
END_RCPP
}
// get_top
IntegerVector get_top(NumericMatrix board);
RcppExport SEXP c4dougbot2000_get_top(SEXP boardSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericMatrix >::type board(boardSEXP);
    rcpp_result_gen = Rcpp::wrap(get_top(board));
    return rcpp_result_gen;
END_RCPP
}
// get_top_lengths
IntegerVector get_top_lengths(NumericMatrix board, int target);
RcppExport SEXP c4dougbot2000_get_top_lengths(SEXP boardSEXP, SEXP targetSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericMatrix >::type board(boardSEXP);
    Rcpp::traits::input_parameter< int >::type target(targetSEXP);
    rcpp_result_gen = Rcpp::wrap(get_top_lengths(board, target));
    return rcpp_result_gen;
END_RCPP
}
