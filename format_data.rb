a = ((`dd`.split(/\n/)[6..-1]*"").gsub(/(Execution time: |#\d+ iteration)/," ").gsub(/ seconds/,", ").split(/Executing with n = \d+/).map{|a|a.split(", ").map(&:to_f).sum/10}.map.with_index{|x,i|"("+(2**(i%9)*16).to_s+", "+x.to_s+")"})
for i in 0...a.size/9 do
 print a[i*9...i*9+9]*"","\n"
end