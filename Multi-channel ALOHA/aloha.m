clc;
clear;
close all;
nfig = 1;
cnt = 1;
fileId = fopen('alohaN.txt', 'r');
arr = fscanf(fileId, '%f ');
lambda = 0.1:0.01:0.9;
figure(nfig);
hold on;
for i = 1:9
   plot(lambda, arr(cnt:(cnt+80)));
   cnt = cnt + 81;
end
xlabel('lambda');
ylabel('Clients');
title('Multi-channel ALOHA');
legend('p = 0.1', 'p = 0.2', 'p = 0.3', 'p = 0.4', 'p = 0.5', 'p = 0.6', 'p = 0.7', 'p = 0.8', 'p = 0.9');
nfig = nfig + 1;
figure(nfig);
fileId = fopen('alohaD.txt', 'r');
arr = fscanf(fileId, '%f ');
hold on;
cnt = 1;
for i = 1:9
   plot(lambda, arr(cnt:(cnt+80)));
   cnt = cnt + 81;
end
xlabel('lambda');
ylabel('Delay');
title('Multi-channel ALOHA');
legend('p = 0.1', 'p = 0.2', 'p = 0.3', 'p = 0.4', 'p = 0.5', 'p = 0.6', 'p = 0.7', 'p = 0.8', 'p = 0.9');
nfig = nfig + 1;
figure(nfig);
fileId = fopen('alohaS.txt', 'r');
arr = fscanf(fileId, '%f ');
hold on;
cnt = 1;
for i = 1:9
   plot(lambda, arr(cnt:(cnt+80)));
   cnt = cnt + 81;
end
xlabel('lambda');
ylabel('Output');
title('Multi-channel ALOHA');
legend('p = 0.1', 'p = 0.2', 'p = 0.3', 'p = 0.4', 'p = 0.5', 'p = 0.6', 'p = 0.7', 'p = 0.8', 'p = 0.9');
nfig = nfig + 1;