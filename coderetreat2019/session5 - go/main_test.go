package main

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestNextAliveForLive(t *testing.T) {
	tests := []struct {
		name       string
		neighbours int
		expected   bool
	}{
		{"0", 0, false},
		{"1", 1, false},
		{"2", 2, true},
		{"3", 3, true},
		{"4", 4, false},
		{"5", 5, false},
		{"6", 6, false},
		{"7", 7, false},
		{"8", 8, false},
	}
	for _, test := range tests {
		t.Run(test.name, func(t *testing.T) {
			alive := nextAliveForLive(test.neighbours)
			assert.Equal(t, test.expected, alive)
		})
	}
}

func TestNextAliveForDead(t *testing.T) {
	tests := []struct {
		name       string
		neighbours int
		expected   bool
	}{
		{"0", 0, false},
		{"1", 1, false},
		{"2", 2, false},
		{"3", 3, true},
		{"4", 4, false},
		{"5", 5, false},
		{"6", 6, false},
		{"7", 7, false},
		{"8", 8, false},
	}
	for _, test := range tests {
		t.Run(test.name, func(t *testing.T) {
			alive := nextAliveForDead(test.neighbours)
			assert.Equal(t, test.expected, alive)
		})
	}
}

func TestInitBoard(t *testing.T) {
	boardSize = 4
	liveCells := []position{{0, 0}, {1, 1}, {2, 2}}
	initBoard(boardSize, liveCells)
	bSize, board := getBoard()
	assert.Equal(t, boardSize, bSize)
	assert.Equal(t, [][]int{{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}}, board)
}

func TestCountNeighbours(t *testing.T) {
	boardSize = 4
	liveCells := []position{{0, 0}, {1, 1}, {2, 2}}
	initBoard(boardSize, liveCells)

	numOfNeighbours := countNeighbours(position{1, 1})
	assert.Equal(t, 2, numOfNeighbours)

}
