int sum = 0;
for(int x = 0; x <= radius; x++)
  sum += Math.sqrt(radius * radius - x * x);
sum = sum * 4 + 1;