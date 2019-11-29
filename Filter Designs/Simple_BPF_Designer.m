%%
%Bandpass Filter Designer - This program uses a for Loop (for fun, not practical)
%Ian Taylor
%ECE411 - Practicum (Team #2)
R = 10000;
prompt1 = "What is your lower frequency?";
prompt2 = "What is your higher frequency?";

%Determine the 8 BPFs for the circuit
for i=1:1:8
%User inputs lower frequency
f1(i) = input(prompt1);
%User inputs higher frequency
f2(i) = input(prompt2);
%Calculate center frequency
fr(i) = sqrt(f1(i).*f2(i));
disp(fr)
%Determines high pass capacitor
c1(i) = 1./(2*pi.*f1(i).*R);
disp(c1(i))
%Determine 
c2(i) = 1./(2.*pi.*f2(i)*R);
disp(c2(i))
end
disp(fr)
disp(f1)
disp(f2)
disp(c1)
disp(c2)
%%
%Ian Taylor
%ECE411 - Practicum (Team #2)
%More practical program, one filter at a time
R = 1000;
prompt1 = 'What is your lower frequency?';
prompt2 = 'What is your higher frequency?';

%User inputs lower frequency (Hz)
f1 = input(prompt1);
%User inputs higher frequency (Hz)
f2 = input(prompt2);
%Calculate center frequency (Hz)
fr = sqrt(f1*f2);
disp(fr)
%Determines high pass capacitor value (F)
c1 = 1/(2*pi*f1*R);
disp(c1)
%Determines low pass capacitor value (F)
c2 = 1/(2*pi*f2*R);
disp(c2)

prompt3 = 'Would you like to adjust';
x = input(prompt3);
if x == 1
   %User inputs closest nominal capacitor values
   c1 = input('What is the closest nominal capacitor value for C1?');
   c2 = input('What is the closest nominal capacitor value for C2?');
   f1 = 1/(2*pi*R*c1);
   disp(f1)
   f2 = 1/(2*pi*R*c2);
   disp(f2)
   fr = sqrt(f1*f2);
   disp(fr)
end

%%
LC
