a = ((`dd`.split(/\n/)[6..-1]*"").gsub(/(Execution time: |#\d iteration)/,"").gsub(/ seconds/,", ").split(/Executing with n = \d+/).map{|a|a.split(", ").map(&:to_f).sum/5})

for i in 0...a.size/9 do
 print a[i*9...i*9+9],"\n"
end