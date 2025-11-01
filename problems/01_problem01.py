# merge intervals

Intervals = [[1,3],[2,6],[8,10],[15,18]]
# [[1,6],[8,10],[15,18]]

def MergeIntervals(I):
    I.sort(key=lambda x: x[0])
    stack = []
    for interval in I:
        if not stack:
            stack.append(interval)
        else:
            top = stack[-1]
            if top[1] >= interval[0]:
                stack[-1] = [top[0], max(top[1], interval[1])]
            else:
                stack.append(interval)
    return stack

print(MergeIntervals(Intervals))