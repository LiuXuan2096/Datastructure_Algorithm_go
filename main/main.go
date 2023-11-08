package main

import (
	"DataStructure_Algorithm_go"
	"fmt"
)

func main() {
	trie := DataStructure_Algorithm_go.Constructor()
	trie.Insert("apple")
	trie.Insert("apple")
	trie.Erase("apple")
	trie.Erase("apple")
	fmt.Println(trie.CountWordsStartingWith("app"))
}
