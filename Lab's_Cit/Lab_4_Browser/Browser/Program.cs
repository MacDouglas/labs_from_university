using System;
using System.Windows.Forms;
using System.Security.Permissions;
using System.ComponentModel;

[PermissionSet(SecurityAction.Demand, Name = "FullTrust")]
public class Form1 : Form
{
    public Form1()
    {
        InitializeForm();

        webBrowser1.CanGoBackChanged +=
            new EventHandler(webBrowser1_CanGoBackChanged);
        webBrowser1.CanGoForwardChanged +=
            new EventHandler(webBrowser1_CanGoForwardChanged);
        webBrowser1.DocumentTitleChanged +=
            new EventHandler(webBrowser1_DocumentTitleChanged);
        webBrowser1.StatusTextChanged +=
            new EventHandler(webBrowser1_StatusTextChanged);

        webBrowser1.GoHome();


    }

    private void toolStripTextBox1_Click(object sender, EventArgs e)
    {
        toolStripTextBox1.SelectAll();
    }
    private void toolStripTextBox1_KeyDown(object sender, KeyEventArgs e)
    {
        if (e.KeyCode == Keys.Enter)
        {
            Navigate(toolStripTextBox1.Text);
        }
    }
    private void goButton_Click(object sender, EventArgs e)
    {
        Navigate(toolStripTextBox1.Text);
    }
    private void Navigate(String address)
    {
        if (String.IsNullOrEmpty(address)) return;
        if (address.Equals("about:blank")) return;
        if (!address.StartsWith("http://") &&
            !address.StartsWith("https://"))
        {
            address = "http://" + address;
        }
        try
        {
            webBrowser1.Navigate(new Uri(address));
        }
        catch (System.UriFormatException)
        {
            return;
        }
    }
    private void webBrowser1_Navigated(object sender,
        WebBrowserNavigatedEventArgs e)
    {
        toolStripTextBox1.Text = webBrowser1.Url.ToString();
    }
    private void backButton_Click(object sender, EventArgs e)
    {
        webBrowser1.GoBack();
    }
    private void webBrowser1_CanGoBackChanged(object sender, EventArgs e)
    {
        backButton.Enabled = webBrowser1.CanGoBack;
    }
    private void forwardButton_Click(object sender, EventArgs e)
    {
        webBrowser1.GoForward();
    }
    private void webBrowser1_CanGoForwardChanged(object sender, EventArgs e)
    {
        forwardButton.Enabled = webBrowser1.CanGoForward;
    }
    private void stopButton_Click(object sender, EventArgs e)
    {
        webBrowser1.Stop();
    }
    private void refreshButton_Click(object sender, EventArgs e)
    {
        // Skip refresh if about:blank is loaded to avoid removing
        // content specified by the DocumentText property.
        if (!webBrowser1.Url.Equals("about:blank"))
        {
            webBrowser1.Refresh();
        }
    }
    private void homeButton_Click(object sender, EventArgs e)
    {
        webBrowser1.GoHome();
    }
    private void searchButton_Click(object sender, EventArgs e)
    {
        webBrowser1.GoSearch();
    }
    private void webBrowser1_StatusTextChanged(object sender, EventArgs e)
    {
        toolStripStatusLabel1.Text = webBrowser1.StatusText;
    }
    private void webBrowser1_DocumentTitleChanged(object sender, EventArgs e)
    {
        this.Text = webBrowser1.DocumentTitle;
    }

    

    private WebBrowser webBrowser1;

    private ToolStrip toolStrip1, toolStrip2;
    private ToolStripTextBox toolStripTextBox1;
    private ToolStripButton goButton, backButton,
        forwardButton, stopButton, refreshButton,
        homeButton, searchButton;

    private StatusStrip statusStrip1;
    private ToolStripStatusLabel toolStripStatusLabel1;
    private void InitializeForm()
    {
        webBrowser1 = new WebBrowser();

        toolStrip1 = new ToolStrip();
        toolStrip2 = new ToolStrip();

        goButton = new ToolStripButton();
        backButton = new ToolStripButton();
        forwardButton = new ToolStripButton();
        stopButton = new ToolStripButton();
        refreshButton = new ToolStripButton();
        homeButton = new ToolStripButton();
        searchButton = new ToolStripButton();

        toolStripTextBox1 = new ToolStripTextBox();

        statusStrip1 = new StatusStrip();
        toolStripStatusLabel1 = new ToolStripStatusLabel();

        toolStrip2.Items.AddRange(new ToolStripItem[] {
            toolStripTextBox1});

        toolStrip1.Items.AddRange(new ToolStripItem[] {
            goButton, backButton, forwardButton, stopButton,
            refreshButton, homeButton, searchButton});

        goButton.Text = "Go";
        backButton.Text = "Back";
        forwardButton.Text = "Forward";
        stopButton.Text = "Stop";
        refreshButton.Text = "Refresh";
        homeButton.Text = "Home";
        searchButton.Text = "Search";

        backButton.Enabled = false;
        forwardButton.Enabled = false;

        goButton.Click += new System.EventHandler(goButton_Click);
        backButton.Click += new System.EventHandler(backButton_Click);
        forwardButton.Click += new System.EventHandler(forwardButton_Click);
        stopButton.Click += new System.EventHandler(stopButton_Click);
        refreshButton.Click += new System.EventHandler(refreshButton_Click);
        homeButton.Click += new System.EventHandler(homeButton_Click);
        searchButton.Click += new System.EventHandler(searchButton_Click);

        toolStripTextBox1.Size = new System.Drawing.Size(250, 25);
        toolStripTextBox1.KeyDown +=
            new KeyEventHandler(toolStripTextBox1_KeyDown);
        toolStripTextBox1.Click +=
            new System.EventHandler(toolStripTextBox1_Click);

        statusStrip1.Items.Add(toolStripStatusLabel1);

        webBrowser1.Dock = DockStyle.Fill;
        webBrowser1.Navigated +=
            new WebBrowserNavigatedEventHandler(webBrowser1_Navigated);

        Controls.AddRange(new Control[] {
            webBrowser1, toolStrip2 ,toolStrip1, statusStrip1});
    }

    [STAThread]
    static void Main()
    {
        Application.EnableVisualStyles();
        Application.Run(new Form1());
    }

}