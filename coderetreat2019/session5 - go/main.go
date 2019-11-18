package main

import "fmt"

var board [][]int
var boardSize int

const (
	dead  = 0
	alive = 1
)

type position struct {
	x int
	y int
}

func main() {
	fmt.Printf("Started")
}

func nextAliveForLive(numOfNeighbours int) bool {
	return numOfNeighbours == 2 || numOfNeighbours == 3
}

func nextAliveForDead(numOfNeighbours int) bool {
	return numOfNeighbours == 3
}

func countNeighbours(pos position) int {
	return 0
}

func initBoard(bSize int, liveCells []position) {
	boardSize = bSize

	board = make([][]int, boardSize, boardSize)
	for i := range board {
		board[i] = make([]int, boardSize, boardSize)
	}

	for _, cell := range liveCells {
		board[cell.x][cell.y] = alive
	}
}

func getBoard() (int, [][]int) {
	return boardSize, board
}
