# Title     : monty hall simulation
# Objective : to switch or not to switch? that is the question.
# Created by: connorfrank
# Created on: 04.12.2020

noChange <- function(trials) {
  wins <- 0
  for (i in 0:trials) {
    prize <- sample(0:2,1)
    choice <- sample(0:2,1)
    if (any(choice == prize)) {
      wins <- wins+1
    }
  }
  out <- wins
}

yesChange <- function(trials) {
  wins <- 0
  for (i in 0:trials) {
    prize <- sample(0:2,1)
    choice <- sample(0:2,1)

    wrong <- prize
    while (wrong == prize || wrong == choice)
      wrong <- sample(0:2,1)

    other <- 3 - (choice + wrong)
    if (any(other == prize)) {
      wins <- wins+1
    }
  }
  out <- wins
}

cat("monty hall simulation\n")
trials <- as.numeric(readline(prompt="enter number of trials (recommended = 1000000): "))

cat("\n")
cat("door unchanged:\n")
noChangeWins <- noChange(trials)
cat(paste0("total wins out of ",trials,": ",noChangeWins,"\n"))
cat(paste0("percent win: ",as.double(noChangeWins/trials)*100,"%\n"))

cat("\n")
cat("door changed:\n")
yesChangeWins <- yesChange(trials)
cat(paste0("total wins out of ",trials,": ",yesChangeWins,"\n"))
cat(paste0("percent win: ",as.double(yesChangeWins/trials)*100,"%\n"))