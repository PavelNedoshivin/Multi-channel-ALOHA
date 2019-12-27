clc;
clear;
close all;
nfig = 1;
cnt = 1;
fileId = fopen('experimentN.txt', 'r');
arr = fscanf(fileId, '%f ');
lambda = 0.1:0.01:0.99;
figure(nfig);
hold on;
for i = 1:2
   plot(lambda, arr(cnt:(cnt+89)));
   cnt = cnt + 90;
end
xlabel('lambda');
ylabel('Clients');
title('Multi-channel ALOHA');
legend('1 channel', '2 channels');
nfig = nfig + 1;
figure(nfig);
fileId = fopen('experimentD.txt', 'r');
arr = fscanf(fileId, '%f ');
hold on;
cnt = 1;
for i = 1:2
   plot(lambda, arr(cnt:(cnt+89)));
   cnt = cnt + 90;
end
xlabel('lambda');
ylabel('Delay');
title('Multi-channel ALOHA');
legend('1 channel', '2 channels');
nfig = nfig + 1;
figure(nfig);
fileId = fopen('experimentS.txt', 'r');
arr = fscanf(fileId, '%f ');
hold on;
cnt = 1;
for i = 1:2
   plot(lambda, arr(cnt:(cnt+89)));
   cnt = cnt + 90;
end
xlabel('lambda');
ylabel('Output');
title('Multi-channel ALOHA');
legend('1 channel', '2 channels');
nfig = nfig + 1;