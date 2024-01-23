// ta co from la coc A, to la coc C, ohter la coc B ( coc trung gian)
function solveHanoi(
    count: number,
    from: string,
    to: string,
    other: string,
    move: (from: string, to: string) => void
)
{
    if (count > 0){
        // di chuyen n - 1 dia tren cung sang coc B thong qua cot C
        solveHanoi(count - 1, from, other, to, move);
        move(from, to);
        // di chuyen dia con lai qua cot C
        // di chuyen n-1 dia tu COT B sang cot C
        solveHanoi(count - 1, other, to, from, move);
    }
}
var movecount = 0;
solveHanoi(6, "Left", "Right", "Middle", (from, to)=>{
    ++movecount;
    console.log(movecount + ": Move from " + from + " to " + to + ".")
})
