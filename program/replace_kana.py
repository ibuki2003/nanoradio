import re
import sys

kana_regex = re.compile(r'([｡-ﾟジ放送第])')
quote_regex = re.compile(r'( "")+([ }])')

for line in sys.stdin:
    line = kana_regex.sub('" \\1 "', line)
    line = quote_regex.sub('\\2', line)
    sys.stdout.write(line)

