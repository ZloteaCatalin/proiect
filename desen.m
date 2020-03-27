A=load('emg_healthy.txt');
figure(1),plot(A(:,1),A(:,2)),title('emg healty'),grid

B=load('emg_myopathy.txt');
figure(2),plot(B(:,1),B(:,2)),title('emg myopathy'),grid 

C=load('emg_neuropathy.txt');
figure(3),plot(C(:,1),C(:,2)),title('emg neuropathy'),grid

