context("create a dougbot")

test_that("Can make a bot", {

  db <- dougbot2000$new(name = "crusher")
  expect_is(db, "dougbot2000")

})
