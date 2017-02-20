#' The unbeatable dougbot2000 c4 player!
#'
#' @section Public Members and Methods:
#'
#' `name`: character. The name of the bot.
#'
#' `make_move(board, lastMove)`: Get the next move, supply the current board matrix and the last move
#'
#' `rejected(board, lastMove)`: Get the next move, supply the current board matrix and the last move
#'
#' @export dougbot2000
#'
#' @importFrom R6 R6Class
#'
#' @examples
#' dougbot2000$new(name="dougbotkill")
#'
dougbot2000 <- R6Class("dougbot2000",

  public = list(
    name = "character",

    make_move = function(board, lastMove) {
      private$moveCnt <- private$moveCnt + 1
      # Cyclic repeat the sequence
      return(private$moveSeq[(private$moveCnt-1) %% length(private$moveSeq) + 1])
    },

    rejected = function(board, lastMove) {
      make_move(board, lastMove)
    },

    initialize=function(moveSeq = c(1,3,4,1,5,6,2,7), name = "dougbotkill") {
      private$moveSeq <- moveSeq
      private$moveCnt <- 0
      self$name <- name
    }),

  private = list(
    moveSeq = "numeric",
    moveCnt = "numeric"
  )
)
