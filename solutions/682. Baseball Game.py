class Solution:
    def calPoints(self, ops: List[str]) -> int:
        record_list = []
        s = 0
        for operator in ops:
            if operator == 'C':
                s -= record_list.pop()
            elif operator == 'D':
                prev = record_list[-1]
                s += prev * 2
                record_list.append(prev * 2)
            elif operator == '+':
                record_list.append(sum(record_list[-2:]))
                s += record_list[-1]
            else: 
                record_list.append(int(operator))
                s += record_list[-1]
        return s
