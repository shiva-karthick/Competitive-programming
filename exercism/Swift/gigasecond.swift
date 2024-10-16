// 1 gigasecond is one thousand million seconds, 1,000,000,000.
let dateFormatter = ISO8601DateFormatter()
dateFormatter.formatOptions = [.withFullDate]

let dateTimeFormatter = ISO8601DateFormatter()
dateTimeFormatter.formatOptions = [.withFullDate, .withFullTime]

func gigasecond(from: Date) -> Date {
    return from.addingTimeInterval(1e9)
}

let bar = gigasecond(from: dateFormatter.date(from: "1959-07-19")!)
print(bar)
