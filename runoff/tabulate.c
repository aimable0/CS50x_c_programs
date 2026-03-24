void tabulate(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        // calculate votes
        if (!candidates[i].eliminated)
        {
            for (int j = 0; j < voter_count; j++)
            {
                if (preferences[j][0] == i)
                {
                    candidates[i].votes += 1;
                }
            }
        }
        if (candidates[i].eliminated)
        {
            for (int j = 0; j < voter_count; j++)
            {
                if (preferences[j][0] == i)
                {
                    // add vote to next valid preference.
                    for (int k = 1; k < candidate_count; k++)
                    {
                        if (!candidates[preferences[j][k]].eliminated)
                        {
                            // preferences[j][0] = preferences[j][k];
                            candidates[preferences[j][k]].votes += 1;
                            break; // if we have a valid first preference.
                        }
                    }
                }
            }
        }
    }
    return;
}