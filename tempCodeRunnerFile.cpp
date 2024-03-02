        cout << "Enter one of the following choices:" << endl;
        cout << "1. Add New Element" << endl;
        cout << "2. Display" << endl;
        cout << "3. Exit" << endl;
        cin >> ch;
        switch (ch) {
            case 1:
                addelement(&head);
                break;
            case 2: