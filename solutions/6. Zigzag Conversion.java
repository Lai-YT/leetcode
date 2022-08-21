        }
​
        this.numRows = numRows;
        StringBuilder[] rows = new StringBuilder[Math.min(s.length(), numRows)];
        for (int i = 0; i < rows.length; ++i) {
            rows[i] = new StringBuilder();
        }
​
        currRowNumber = 0;
        /* if start with DOWN, the initial direction change break
            make currRowNumber = -1 */
        direction = ZigzagDirection.UP;
        for (int i = 0; i < s.length(); ++i) {
            rows[currRowNumber].append(s.charAt(i));
​
            if (shouldChangeDirection()) {
                changeDirection();
            }
            currRowNumber += direction.dirCode;
        }
​
        StringBuilder zigzagString = combineRows(rows);
        return zigzagString.toString();
    }
​
    private boolean shouldChangeDirection() {
        return currRowNumber == 0 || currRowNumber == numRows - 1;
    }
​
    private void changeDirection() {
        direction = direction.changeDirection();
    }
​
    private StringBuilder combineRows(StringBuilder[] rows) {
        StringBuilder combinedRows = new StringBuilder();
        for (final StringBuilder row : rows) {
            combinedRows.append(row);
        }
        return combinedRows;
    }
}
​
