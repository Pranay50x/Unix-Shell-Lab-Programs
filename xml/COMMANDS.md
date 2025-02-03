# Commands for xmlstarlet thing

## 1. Making a student.xml file
```bash
xmlstarlet sel -t -c "//student" sample.xml > student.xml
```

## 2. Making a bash script with sed commands for Replacing Name with DeptName
```bash
#!/bin/bash
sed -i 's/Name/DeptName/g' sample.xml
sed -i 's/<\/Name>/<\/DeptName>/g' sample.xml
```

## 3. XMLStarlet command to make usn values separate
```bash
xmlstarlet sel -t -m "//usn" -v "." -n sample.xml | tee u usn.txt
```