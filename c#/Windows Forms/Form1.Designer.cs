namespace C_WF
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            button1 = new Button();
            button2 = new Button();
            buttonTime = new Button();
            button4 = new Button();
            buttonFName = new Button();
            textBox1 = new TextBox();
            button3 = new Button();
            buttonClose = new Button();
            button5 = new Button();
            buttonUnClosedPr = new Button();
            SuspendLayout();
            // 
            // button1
            // 
            button1.Location = new Point(655, 412);
            button1.Name = "button1";
            button1.Size = new Size(75, 23);
            button1.TabIndex = 0;
            button1.Text = "Birthday";
            button1.TextImageRelation = TextImageRelation.TextAboveImage;
            button1.UseVisualStyleBackColor = true;
            // 
            // button2
            // 
            button2.AccessibleRole = AccessibleRole.Window;
            button2.AllowDrop = true;
            button2.AutoEllipsis = true;
            button2.BackColor = SystemColors.ButtonFace;
            button2.Cursor = Cursors.Help;
            button2.DialogResult = DialogResult.Abort;
            button2.FlatStyle = FlatStyle.System;
            button2.Location = new Point(766, 412);
            button2.Name = "button2";
            button2.Size = new Size(75, 23);
            button2.TabIndex = 1;
            button2.Text = "Bulochka";
            button2.UseCompatibleTextRendering = true;
            button2.UseVisualStyleBackColor = false;
            button2.Click += button2_Click;
            // 
            // buttonTime
            // 
            buttonTime.Location = new Point(552, 412);
            buttonTime.Name = "buttonTime";
            buttonTime.Size = new Size(75, 23);
            buttonTime.TabIndex = 2;
            buttonTime.Text = "Time";
            buttonTime.UseVisualStyleBackColor = true;
            buttonTime.Click += buttonFName_Click_1;
            // 
            // button4
            // 
            button4.Location = new Point(450, 412);
            button4.Name = "button4";
            button4.Size = new Size(75, 23);
            button4.TabIndex = 3;
            button4.Text = "Date";
            button4.UseVisualStyleBackColor = true;
            // 
            // buttonFName
            // 
            buttonFName.Location = new Point(354, 412);
            buttonFName.Name = "buttonFName";
            buttonFName.Size = new Size(75, 23);
            buttonFName.TabIndex = 4;
            buttonFName.Text = "FullName";
            buttonFName.UseVisualStyleBackColor = true;
            buttonFName.Click += buttonFName_Click_1;
            // 
            // textBox1
            // 
            textBox1.Location = new Point(218, 28);
            textBox1.Multiline = true;
            textBox1.Name = "textBox1";
            textBox1.Size = new Size(432, 23);
            textBox1.TabIndex = 5;
            textBox1.Visible = false;
            // 
            // button3
            // 
            button3.Location = new Point(388, 181);
            button3.Name = "button3";
            button3.Size = new Size(102, 53);
            button3.TabIndex = 6;
            button3.Text = "hahan't";
            button3.UseVisualStyleBackColor = true;
            button3.Click += button3_Click;
            button3.MouseEnter += button3_Change;
            // 
            // buttonClose
            // 
            buttonClose.Location = new Point(251, 412);
            buttonClose.Name = "buttonClose";
            buttonClose.Size = new Size(75, 23);
            buttonClose.TabIndex = 7;
            buttonClose.Text = "close";
            buttonClose.UseVisualStyleBackColor = true;
            buttonClose.Click += buttonClose_Click;
            // 
            // button5
            // 
            button5.Location = new Point(143, 412);
            button5.Name = "button5";
            button5.Size = new Size(75, 23);
            button5.TabIndex = 8;
            button5.Text = "button5";
            button5.UseVisualStyleBackColor = true;
            button5.Click += button5_Click;
            // 
            // buttonUnClosedPr
            // 
            buttonUnClosedPr.Location = new Point(41, 412);
            buttonUnClosedPr.Name = "buttonUnClosedPr";
            buttonUnClosedPr.Size = new Size(75, 23);
            buttonUnClosedPr.TabIndex = 9;
            buttonUnClosedPr.Text = "HEHEHEHE";
            buttonUnClosedPr.UseVisualStyleBackColor = true;
            buttonUnClosedPr.Click += buttonUnClosedPr_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            AutoSize = true;
            BackColor = SystemColors.ActiveCaptionText;
            ClientSize = new Size(884, 461);
            Controls.Add(buttonUnClosedPr);
            Controls.Add(button5);
            Controls.Add(buttonClose);
            Controls.Add(button3);
            Controls.Add(textBox1);
            Controls.Add(buttonFName);
            Controls.Add(button4);
            Controls.Add(buttonTime);
            Controls.Add(button2);
            Controls.Add(button1);
            Name = "Form1";
            SizeGripStyle = SizeGripStyle.Show;
            StartPosition = FormStartPosition.CenterScreen;
            Tag = "Lalalala";
            Text = "FirstWindow";
            TransparencyKey = Color.FromArgb(192, 0, 0);
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Button button1;
        public Button button2;
        private Button buttonTime;
        private Button button4;
        private Button buttonFName;
        private TextBox textBox1;
        private Button button3;
        private Button buttonClose;
        private Button button5;
        private Button buttonUnClosedPr;
    }
}