module Example exposing (..)

import Expect exposing (Expectation)
import Fuzz exposing (Fuzzer, int, list, string)
import Test exposing (..)

event: Msg -> Game -> Game
event msg game =
    case msg of  
        LivingCell x y ->
            Game ((Position x y) :: game.livingCells)
        Tick ->
            game.livingCells
            |> List.filter 
            (\position ->
                case List.length (neighboursAlive position game) of
                    2 ->
                        True
                    _ ->
                        False
            )

type Msg
    = Tick |
    LivingCell Int Int 

type alias Position = { x : Int, y : Int }

type alias Game = {
        livingCells: List Position
    }

getNeighbors position game =
    let 
        columnLeft = position.x - 1
        columnRight = position.x + 1
        rowDown = position.y - 1
        rowUp = position.y + 1
    in
        [Position columnLeft rowUp, Position position.x rowUp, Position columnRight rowUp] ++
        [Position columnLeft position.y, Position columnRight position.y] ++
        [Position columnLeft rowDown, Position position.x rowDown, Position columnRight rowDown]

    {--    |> List.map--}

isAlive: Position -> Game -> Bool
isAlive position game =
    List.member position game.livingCells

neighboursAlive position game =
    getNeighbors position game  
    |> List.filter (\point -> isAlive point game)


blah : Test
blah =
    test "blah" <|
        \_ ->
            Expect.equal (event Tick (Game [])) (Game [])

testSendLivingCell =
    test "can add a living cell to game" <|
    \_ ->
        event (LivingCell 2 2) (Game [])
        |> .livingCells
        |> List.length
        |> Expect.equal 1 
    {--
testCellDies =
    todo "lonely cell dies on tick" <|
    \_ ->
        event (LivingCell 2 2) (Game [])
        |> event Tick 
        |> .livingCells
        |> List.length
        |> Expect.equal 0 
 --}   
testCellHasEightNeighbore =
    test "a cell always has eight neighbors" <|
    \_ ->
        Game []
        |> getNeighbors (Position 3 3)
        |> List.length
        |> Expect.equal 8


testPositionIsAlive =
    test "cell is alive" <|
    \_ -> 
        Game []
        |> event (LivingCell 4 2)
        |> isAlive (Position 4 2)
        |> Expect.equal True

testNeighboursAlive =
    test "number of neighbours alive" <|
    \_ -> 
        Game []
        |> event (LivingCell 4 2)
        |> neighboursAlive (Position 3 2)
        |> List.length
        |> Expect.equal 1

testRuleTwo =
    test "cell with 2 or 3 living neighbors still lives" <|
    \_ ->
        Game []
        |> event (LivingCell 0 2)
        |> event (LivingCell 1 1)
        |> event (LivingCell 2 0)
        |> event Tick
        |> isAlive (Position 1 1)
        |> Expect.equal True

