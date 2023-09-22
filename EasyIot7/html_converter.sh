tail -n +2 ../html/js/index.js > ../html/js/index.tmp.js
echo "let baseUrl= \"\"\n$(cat ../html/js/index.tmp.js)" > ../html/js/index.tmp.js 

html-minifier --collapse-whitespace ../html/devices.html -o ../html/devices.min.html
html-minifier --collapse-whitespace ../html/index.html -o ../html/index.min.html
html-minifier --collapse-whitespace ../html/node.html -o ../html/node.min.html
uglifyjs  --compress --mangle -o ../html/js/index.min.js ../html/js/index.tmp.js
uglifycss ../html/css/styles.css > ../html/css/styles.min.css


gzip -k  ../html/devices.min.html
gzip -k  ../html/index.min.html   
gzip -k  ../html/node.min.html
gzip -k  ../html/js/index.min.js
gzip -k  ../html/css/styles.min.css

xxd -i -n devices_html ../html/devices.min.html.gz > include/DevicesHtml.h 
sed -i "" "s/\[\]/\[\] PROGMEM/" include/DevicesHtml.h
echo "#include <Arduino.h>\n\r$(cat include/DevicesHtml.h)" > include/DevicesHtml.h 

xxd -i -n index_html ../html/index.min.html.gz > include/IndexHtml.h 
sed -i "" "s/\[\]/\[\] PROGMEM/" include/IndexHtml.h
echo "#include <Arduino.h>\n\r$(cat include/IndexHtml.h)" > include/IndexHtml.h 

xxd -i -n node_html ../html/node.min.html.gz > include/NodeHtml.h 
sed -i "" "s/\[\]/\[\] PROGMEM/" include/NodeHtml.h
echo "#include <Arduino.h>\n\r$(cat include/NodeHtml.h)" > include/NodeHtml.h 

xxd -i -n index_js ../html/js/index.min.js.gz > include/IndexJs.h 
sed -i "" "s/\[\]/\[\] PROGMEM/" include/IndexJs.h
echo "#include <Arduino.h>\n\r$(cat include/IndexJs.h)" > include/IndexJs.h 

xxd -i -n styles_min_css ../html/css/styles.min.css.gz > include/StylesMinCss.h 
sed -i "" "s/\[\]/\[\] PROGMEM/" include/StylesMinCss.h
echo "#include <Arduino.h>\n\r$(cat include/StylesMinCss.h)" > include/StylesMinCss.h 

rm -f ../html/js/index.tmp.js
rm -f  ../html/devices.min.html
rm -f  ../html/index.min.html   
rm -f  ../html/node.min.html 
rm -f  ../html/css/styles.min.css
rm -f  ../html/js/index.min.js
rm -f  ../html/devices.min.html.gz
rm -f  ../html/index.min.html.gz   
rm -f  ../html/node.min.html.gz 
rm -f  ../html/js/index.min.js.gz 
rm -f  ../html/css/styles.min.css.gz 