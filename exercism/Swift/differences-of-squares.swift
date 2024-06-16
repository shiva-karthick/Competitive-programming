class Squares{
    var number: Int
    
    init(_ number : Int) {
        self.number = number
    }
    
    var squareOfSum: Int{
        var sum: Int = 0
        for n in 1...self.number{
            sum += n
        }
        return sum * sum
    }
    var sumOfSquares: Int{
        var sum: Int = 0
        for n in 1...self.number{
            sum += (n * n)
        }
        return sum
    }
    
    var differenceOfSquares: Int{
        return squareOfSum - sumOfSquares
    }
}