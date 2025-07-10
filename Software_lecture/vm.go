package main

import "fmt"

var x int = 42

func Foo() *int {
	i := 1
	return &i
}

func main() {
	fmt.Println("Golang pointer demo\n")

	fmt.Printf(" x:  %d\n", x)

	xp := &x
	fmt.Printf("&x:  %p\n", xp)

	y := 42
	fmt.Printf(" y:  %d\n", y)

	yp := &y
	fmt.Printf("&y:  %p\n", yp)

	z := Foo()
	fmt.Printf(" z:  %p\n", z)
	fmt.Printf("*z:  %p\n", *z) // jst means what z is pointing to but with weird go syntax.
}