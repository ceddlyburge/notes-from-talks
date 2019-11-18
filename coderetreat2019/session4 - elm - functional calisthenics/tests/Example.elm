module Example exposing (..)

import Expect exposing (Expectation)
import Fuzz exposing (Fuzzer, int, list, string)
import Test exposing (..)

type alias Position = { x : Int, y : Int }

type Breathing = 
    Alive
    | Dead

type alias LiveNeighbours = Int

neighboursLessThan2 = 2

neighbourCellDistanceLimit = 1

livesOrDies: Position -> List Position -> Breathing
livesOrDies position livingCells =
    if (countNeighbours position livingCells) < neighboursLessThan2 then
        Dead
    else 
        Alive

countNeighbours: Position -> List Position -> LiveNeighbours
countNeighbours position livingCells =
    List.filter (isNeighbour position) livingCells
    |> List.length

isNeighbour: Position -> Position -> Bool
isNeighbour cellPosition livingCellPosition =
    abs(cellPosition.x - livingCellPosition.x) <= neighbourCellDistanceLimit
    && abs(cellPosition.y - livingCellPosition.y) <= neighbourCellDistanceLimit
    && not (
        cellPosition.x == livingCellPosition.x 
        && cellPosition.y == livingCellPosition.y
    )



livesOrDiesTest : Test
livesOrDiesTest =
    test "livesOrDies" <| 
        \_ -> 
            livesOrDies (Position 1 1) [Position 1 0, Position 1 1 ]
            |> Expect.equal Dead

