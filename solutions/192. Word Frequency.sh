#!/usr/bin/env bash

# replace sequence of ' ' with a single '\n'
tr --squeeze-repeats ' ' '\n' <words.txt |
  # so same words group together and uniq can be used \
  sort |
  uniq --count |
  # sort by count numerically in descending order \
  sort --numeric-sort --reverse |
  # put the count after the word \
  awk '{ print $2, $1 }'
