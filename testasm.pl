use IO::All;

$/ = undef;

@answers = (
    233168,
    4613732,
    6857,
    906609,
);

for $asm (sort @ARGV) {
    $asm =~ /(\d+)/;
    $probno = $1;
    die("prob # undetermined: $asm") unless $probno;
    die("no answer for prob #$probno") unless (1 <= $probno and $probno <= @answers);

    print STDERR "testing $asm\n";
    
    io($asm)->all =~ /call\t___main\n\tmovl\t\$(-?\d+), \%eax/ or die("unexpected format");
    $result = $1;

    die("test failure $asm - expected: $answers[$probno-1]; found: $result") if $answers[$probno-1] != $result;

    print STDERR "[PASSED]\n";
}

exit(0); # all tests passed

