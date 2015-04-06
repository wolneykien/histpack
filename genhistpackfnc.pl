#!/usr/bin/perl

use strict;

my @vals = ();
for (my $n = 0; $n < 16; $n++)
{
    $vals[$n] = [];
}

for (my $x = 0; $x < 65536; $x++)
{
    for (my $n = 0; $n < 16; $n++)
    {
        my $f = 0x0001 << $n;
        if (($x & $f) != 0) {
            push (@{$vals[$n]}, $x);
        }
    }
}

print "#include <stdint.h>\n";
print "\n";

for (my $n = 0; $n < 16; $n++)
{
    print "COUNTERTYPE fn$n (COUNTERTYPE *hist)\n";
    print "{\n";
    print "    COUNTERTYPE res = 0;\n";
    foreach my $x (@{$vals[$n]})
    {
        print "    res += hist[$x];\n";
    }
    print "    return res;\n";
    print "}  /* end of fn$n */\n";
}
