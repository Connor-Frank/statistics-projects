a <- as.numeric(readline(prompt="a = "))
b <- as.numeric(readline(prompt="b = "))
c <- as.numeric(readline(prompt="c = "))

discriminant <- b^2 - 4*a*c

if (discriminant > 0) {
	x1 <- (-b + sqrt(discriminant)) / (2*a)
	x2 <- (-b - sqrt(discriminant)) / (2*a)
	cat(paste0("real roots:\n",x1,"\t",x2,"\n"))
} else if (discriminant == 0) {
	x1 <- -b / (2*a)
	cat(paste0("real root:\n",x1,"\n"))
} else {
	cat("no real roots.\n")
}