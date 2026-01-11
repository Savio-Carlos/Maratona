    #!/bin/bash
set -e
GEN=./gen_tests.py    # path to generator
EXE=./e               # your program
VER=./verifier        # verifier from earlier

mkdir -p /tmp/test_batch
i=0
while true; do
  seed=$RANDOM
  python3 $GEN $seed > /tmp/test_batch/input.txt
  # take only the first test block (the generator prints many tests). we'll extract the first test:
  # read N then N lines
  N=$(head -n1 /tmp/test_batch/input.txt)
  total=$((N+1))
  head -n $total /tmp/test_batch/input.txt > /tmp/test_batch/single_input.txt

  $EXE < /tmp/test_batch/single_input.txt > /tmp/test_batch/out.txt
  cat /tmp/test_batch/single_input.txt /tmp/test_batch/out.txt | $VER > /tmp/test_batch/verres.txt 2>&1 || {
    echo "FAILED on iteration $i, seed $seed"
    echo "Input:"
    cat /tmp/test_batch/single_input.txt
    echo "Output:"
    cat /tmp/test_batch/out.txt
    echo "Verifier:"
    cat /tmp/test_batch/verres.txt
    exit 1
  }
  i=$((i+1))
  if (( i % 100 == 0 )); then
    echo "Passed $i tests (last seed $seed)"
  fi
  # run many; stop condition:
  if (( i >= 1000 )); then
    echo "Done 1000 tests OK"
    break
  fi
done
