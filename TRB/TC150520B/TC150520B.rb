#!/usr/bin/ruby -w

puts "Hello, Ruby!";

print <<EOF

    This is the first way of creating
    here document ie. multiple line string.
EOF

print <<"EOF";                # 与上面相同

    This is the second way of creating
    here document ie. multiple line string.
EOF

print <<`EOC`                 # 执行命令
	echo hi there
	echo lo there
EOC

print <<"foo", <<"bar"	      # 您可以把它们进行堆叠
	I said foo.
foo
	I said bar.    
    
bar

=begin
这是注释。
这也是注释。
这也是注释。
这还是注释。
=end

END {
   puts "Terminating Ruby Program"
}

BEGIN {
   puts "Initializing Ruby Program"
}

#整型 Integer 以下是一些整型字面量 
#字面量（literal）：代码中能见到的值，数值，bool值，字符串等都叫字面量 
#如以下的0,1_000_000,0xa等 
a1=0 

#带千分符的整型 
a2=1_000_000 

#其它进制的表示 
a3=0xa 
puts a1,a2 
puts a3 

#puts print 都是向控制台打印字符，其中puts带回车换行符 
=begin 
这是注释，称作：嵌入式文档注释 
类似C#中的/**/ 
=end 


#浮点型 
f1=0.0 
f2=2.1 
f3=1000000.1 
puts f3

#指数算术 
puts 2**(1/4)#1与4的商为0，然后2的0次方为1 
puts 16**(1/4.0)#1与4.0的商为0.25（四分之一），然后开四次方根 

puts 'escape using "\\"';
puts 'That\'s right';

puts "Multiplication Value : #{24*60*60}";

name="Ruby" 
puts name 
puts "#{name+",ok"}" 

ary = [  "fred", 10, 3.14, "This is a string", "last element", ]
ary.each do |i|
   puts i
end

puts ""

hsh = { "red" => 0xf00, "green" => 0x0f0, "blue" => 0x00f }
hsh.each do |key, value|
   print key, " is ", value, "\n"
end

puts ""

(10..15).each do |n| 
   print n, ' ' 
end

puts ""