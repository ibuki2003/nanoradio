import re
import sys

kana_regex = re.compile(r'([｡-ﾟ])')
quote_regex = re.compile(r' ("" )+')

for line in sys.stdin:
    line = kana_regex.sub('" \\1 "', line)
    line = quote_regex.sub(' ', line)
    sys.stdout.write(line)

