package main
import "fmt"
func checkYear(year int) bool {
    return (year % 400 == 0) || (year%4 == 0 && year%100 != 0)
}

func week_f(year int) int{
	if (year == 1) {
		return 1
	}
	var sum = 0
	var i int
	for i = 1; i < year; i++ {
		if (check_year(i) == 1) {
			sum += 366
		}
		if (check_year(i) == 0) {
				sum += 365

		}

		}
	return(sum + 1) % 7
}
var month_run  = []int{ 31,29,31,30,31,30,31,31,30,31,30,31 }
var month_ping = []int{ 31,28,31,30,31,30,31,31,30,31,30,31 }
func run( week int) {
	var i, j, k int
	var wee = week
	for i = 1; i <= 12; i++ {
		var enter = 0
		fmt.Print("------>%d月<------\n",i)
		fmt.Print("日 一 二 三 四 五 六\n")
		for k = 0; k < wee; k++ {
			fmt.Print("    ")
			enter++
		}
	for j = 1; j <= month_run[i]; j++ {
		if(enter % 7 == 0) {
			fmt.Print("\n")

		}
		if (j < 10) {
				fmt.Print("%d  ", j)
				enter++
			}
			if (j >= 10) {
				fmt.Print("%d ", j)
				enter++
			}
	}
	wee = (wee + month_run[i]) % 7
	fmt.Print("\n\n\n")
	}
}
func ping(week int) {
	var wee = week
	var i, j, k int
	for i = 1; i <= 12; i++ {
		var enter = 0
		fmt.Print("------->%d月------<\n",i)
		fmt.Print("日 一 二 三 四 五 六\n")
		for k = 0; k < wee; k++ {
			fmt.Print("    ")
			enter++

		}
	for j = 1; j <= month_ping[i]; j++ {
		if (enter % 7 == 0) {
			fmt.Print("\n")
		}
		if (j < 10) {
				fmt.Print("%d  ", j)
				enter++
			}
			if (j >= 10) {
				fmt.Print("%d ", j)
				enter++
			}
	wee = (wee + month_ping[i]) % 7
	fmt.Print("\n\n\n")
	}
}
func main() {
	var year int
	var week = 0
	var sum = 0
	fmt.Print("请输入年份：")
	fmt.Scan("%d", &year)
	week = week_f(year)
	if (check_year(year) == 1) {
		run(week)
	}
	if (check_year(year) == 0) {
		ping(week)
	}
}
