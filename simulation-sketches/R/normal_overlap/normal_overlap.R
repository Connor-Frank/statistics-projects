# Title     : plots the overlap of normal distributions
# Objective : i put this together after the quiz because i was curious
# Created by: connorfrank
# Created on: 09.12.2020

set.seed(456456)
n <- 100000
mu1 <- 13.5 # alyse
sd1 <- 2.5
mu2 <- 12 # jocelyn
sd2 <- 1.5

xs <- seq(min(mu1 - 3*sd1, mu2 - 3*sd2), max(mu1 + 3*sd1, mu2 + 3*sd2), length.out=n)
f1 <- dnorm(xs, mean=mu1, sd=sd1) # dist1
f2 <- dnorm(xs, mean=mu2, sd=sd2) # dist2

ps <- matrix(c(runif(n, min(xs), max(xs)), runif(n, min=0, max=max(f1,f2)) ), ncol=2) # sample x,y from uniform dist

z1<- ps[,2] <= dnorm(ps[,1], mu1, sd1) # dist1
z2<- ps[,2] <= dnorm(ps[,1], mu2, sd2) # dist 2
z12 <- z1 | z2 # both dists
z3 <- ps[,2] <= pmin(dnorm(ps[,1], mu1, sd1), dnorm(ps[,1], mu2, sd2)) # overlap

# plot
plot(ps[!z12, 1], ps[!z12, 2], col='#137072', pch=20, ylim=c(0, max(f1,f2)), xlim=range(xs), xlab="", ylab="")
points(ps[z1,1], ps[z1,2], col="#FBFFC0")
points(ps[z2,1], ps[z2,2], col="#56B292")
points(ps[z3, 1], ps[z3,2], col="#BF223D")
lines(xs, f1, lwd=2)
lines(xs, f2, lty="dotted",lwd=2)