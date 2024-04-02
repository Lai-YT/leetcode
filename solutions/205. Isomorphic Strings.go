func isIsomorphic(s string, t string) bool {
	const ascii = 128
	hasBeenMapped := [ascii]bool{}
	charMap := make(map[byte]byte)
	for i := range s {
		a := s[i]
		b := t[i]
		bHasBeenMapped := hasBeenMapped[b]
		mappedByA, aHasMappedTo := charMap[a]
		// Either the pair of character hasn't been mapped and mapped to, or it has been mapped together, can the string continued to be considered as isomorphic.
		if !bHasBeenMapped && !aHasMappedTo {
			charMap[a] = b
			hasBeenMapped[b] = true
			continue
		}
		if bHasBeenMapped && aHasMappedTo && mappedByA == b {
			continue
		}
		return false
	}
	return true
}
