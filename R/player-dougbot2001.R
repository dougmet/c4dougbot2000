#' The unbeatable dougbot2001 c4 player!
#'
#' @section Public Members and Methods:
#'
#' `name`: character. The name of the bot.
#'
#' `make_move(board, lastMove)`: Get the next move, supply the current board matrix and the last move
#'
#' `rejected(board, lastMove)`: Get the next move, supply the current board matrix and the last move
#'
#' @export dougbot2001
#'
#' @importFrom R6 R6Class
#'
#' @examples
#' dougbot2001$new(name="dougbotkill", player = 1)
#'
dougbot2001 <- R6Class("dougbot2001",

  public = list(
    name = "character",

    make_move = function(board, lastMove) {
      private$moveCnt <- private$moveCnt + 1

      top <- get_top(board)
      if(all(top < 1)) stop("Can't move")

      # Can you win?
      top_ln_player <- get_top_lengths(board, target = private$player)
      if (any(top_ln_player >= 4, na.rm = TRUE)) {
        i <- which(top_ln_player == max(top_ln_player, na.rm = TRUE))
        return(i[sample.int(length(i), size = 1)])
      }

      # Otherwise block them off
      top_ln_opp <- get_top_lengths(board, target = private$opponent)
      i <- which(top_ln_opp == max(top_ln_opp, na.rm = TRUE))
      return(i[sample.int(length(i), size = 1)])
    },

    rejected = function(board, lastMove) {
      make_move(board, lastMove)
    },

    initialize=function(name = "dougbotkill", player) {
      private$moveCnt <- 0
      stopifnot(any(player==1:2))
      private$player <- player
      private$opponent <- 3 - player
      self$name <- name
    }),

  private = list(
    moveCnt = "numeric",
    player = "integer",
    opponent = "integer"
  )
)
