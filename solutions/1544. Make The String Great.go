func makeGood(s string) string {
	stack := []rune{}
	for _, b := range s {
		if len(stack) == 0 {
			stack = append(stack, b)
			continue
		}
		topI := len(stack) - 1
		top := stack[topI]
		if b != top && (unicode.ToLower(b) == top || unicode.ToUpper(b) == top) {
			stack = stack[:topI]
		} else {
			stack = append(stack, b)
		}
	}
	return string(stack)
}
