import sqlite3

con = sqlite3.connect("saizeriya.db")
cur = con.cursor()

# menu
# 0: id
# 1: name
# 2: category
# 3: type
# 4: price
# 5: calorie
# 6: salt

length = 0
for row in cur.execute("select * from menu;"):
    length += 1
print(length)

for row in cur.execute("select * from menu;"):
    print("{} {} {} {} {} {} {}".format(row[0], row[1], row[2], row[3], row[4], row[5], row[6]))
