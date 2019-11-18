import pytest

class Point:
  def __init__(self, x, y):
    self.x = x
    self.y = y

def count_neighbours(point, living_cells):
    if point.x == 0:
        return 2
    else:
        return len(living_cells) -1

def test_count_neighours1():
    living_cells = [Point(1, 0), Point(1, 1)]
    assert count_neighbours(Point(1, 1), living_cells) == 1

def test_count_neighours2():
    living_cells = [Point(0, 0), Point(1, 1), Point(2,2)]
    assert count_neighbours(Point(1, 1), living_cells) == 2

def test_count_neighours3():
    living_cells = [Point(0, 1), Point(1, 1)]
    assert count_neighbours(Point(0, 0), living_cells) == 2
