int swapBits (int number , int pos1 , int pos2)
{
    int msb = 8 * sizeof(int) - 1;
    if (pos1 < 0 || pos1 > msb || pos2 < 0 || pos2 > msb)
        return number;
    if ( ((number >> (pos1-1)) & 0x01) == ((number >> (pos2-1)) & 0x01) )    // Read Specific bit and if identical
        return number;
    else    // if Not Identical Invert those
    { 
        number = number ^ (1 << (pos1 - 1));
        number = number ^ (1 << (pos2 - 1));
        return number;
    }
}
