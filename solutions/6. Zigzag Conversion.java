class Solution {
    private int numRows;
    private int currRowNumber;
    private ZigzagDirection direction;

    private enum ZigzagDirection {
        DOWN(1) {
            @Override
            ZigzagDirection changeDirection() {
                return ZigzagDirection.UP;
            }
        },
        UP(-1) {
            @Override
            ZigzagDirection changeDirection() {
                return ZigzagDirection.DOWN;
            }
        };

        final int dirCode;

        private ZigzagDirection(int dirCode) {
            this.dirCode = dirCode;
        }

        abstract ZigzagDirection changeDirection();
    }

    public String convert(String s, int numRows) {
        if (numRows == 1) {
            /* not really a zigzag, our direction way can't deal with this */
            return s;
        }

        this.numRows = numRows;
        StringBuilder[] rows = new StringBuilder[Math.min(s.length(), numRows)];
        for (int i = 0; i < rows.length; ++i) {
            rows[i] = new StringBuilder();
        }

        currRowNumber = 0;
        /* if start with DOWN, the initial direction change break
            make currRowNumber = -1 */
        direction = ZigzagDirection.UP;
        for (int i = 0; i < s.length(); ++i) {
            rows[currRowNumber].append(s.charAt(i));

            if (shouldChangeDirection()) {
                changeDirection();
            }
            currRowNumber += direction.dirCode;
        }

        StringBuilder zigzagString = combineRows(rows);
        return zigzagString.toString();
    }

    private boolean shouldChangeDirection() {
        return currRowNumber == 0 || currRowNumber == numRows - 1;
    }

    private void changeDirection() {
        direction = direction.changeDirection();
    }

    private StringBuilder combineRows(StringBuilder[] rows) {
        StringBuilder combinedRows = new StringBuilder();
        for (final StringBuilder row : rows) {
            combinedRows.append(row);
        }
        return combinedRows;
    }
}
