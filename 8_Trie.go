package DataStructure_Algorithm_go

/*
leetCode测试通过
https://leetcode.cn/problems/implement-trie-ii-prefix-tree/description/
*/
type Trie struct {
	Head Node
}

type Node struct {
	Pass  int
	End   int
	Nexts [26]*Node
}

func Constructor() Trie {
	node := Node{
		Pass:  0,
		End:   0,
		Nexts: [26]*Node{nil},
	}
	trie := Trie{
		Head: node,
	}

	return trie
}

func (this *Trie) Insert(word string) {
	if word == "" {
		return
	}
	node := &this.Head
	(*node).Pass++
	var path = 0
	for _, ch := range word { // 从左往右遍历字符
		path = int(ch - 'a') // 确定字符走向哪条路
		if (*node).Nexts[path] == nil {
			(*node).Nexts[path] = new(Node)
		}
		node = (*node).Nexts[path]
		(*node).Pass++
	}
	(*node).End++
}

func (this *Trie) CountWordsEqualTo(word string) int {
	if word == "" {
		return 0
	}
	node := &this.Head
	var index = 0
	for _, ch := range word {
		index = int(ch - 'a')
		if (*node).Nexts[index] == nil {
			return 0
		}
		node = (*node).Nexts[index]
	}
	return (*node).End
}

func (this *Trie) CountWordsStartingWith(prefix string) int {
	if prefix == "" {
		return 0
	}
	node := &this.Head
	var index = 0
	for _, ch := range prefix {
		index = int(ch - 'a')
		if (*node).Nexts[index] == nil {
			return 0
		}
		node = (*node).Nexts[index]
	}
	return (*node).Pass
}

func (this *Trie) Erase(word string) {
	if this.CountWordsEqualTo(word) != 0 {
		// fmt.Println("Erase被执行了-------------")
		node := &this.Head
		(*node).Pass--
		var path = 0
		for _, ch := range word {
			path = int(ch - 'a')
			tempNode := (*node).Nexts[path]
			if (*tempNode).Pass-1 == 0 {
				(*node).Nexts[path] = nil
				return
			}
			(*tempNode).Pass--
			node = tempNode
		}
		(*node).End--
	}
}
