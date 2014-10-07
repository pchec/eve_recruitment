<?php
/**
 * @file
 * Default views of the EVE Recruitment module.
 */


function eve_recruitment_views_default_views() {

	// Recruitment Statistics
	$view = new view();
	$view->name = 'recruitment_statistics';
	$view->description = '';
	$view->tag = 'default';
	$view->base_table = 'eve_recruitment';
	$view->human_name = 'Recruitment Statistics';
	$view->core = 7;
	$view->api_version = '3.0';
	$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

	/* Display: Master */
	$handler = $view->new_display('default', 'Master', 'default');
	$handler->display->display_options['title'] = 'Recruitment Summary';
	$handler->display->display_options['use_more_always'] = FALSE;
	$handler->display->display_options['group_by'] = TRUE;
	$handler->display->display_options['access']['type'] = 'perm';
	$handler->display->display_options['access']['perm'] = 'view statistics';
	$handler->display->display_options['cache']['type'] = 'none';
	$handler->display->display_options['query']['type'] = 'views_query';
	$handler->display->display_options['exposed_form']['type'] = 'basic';
	$handler->display->display_options['pager']['type'] = 'mini';
	$handler->display->display_options['pager']['options']['items_per_page'] = '10';
	$handler->display->display_options['pager']['options']['offset'] = '0';
	$handler->display->display_options['pager']['options']['id'] = '0';
	$handler->display->display_options['style_plugin'] = 'table';
	$handler->display->display_options['style_options']['columns'] = array(
	  'name' => 'name',
	  'name_1' => 'name_1',
	);
	$handler->display->display_options['style_options']['default'] = 'name_1';
	$handler->display->display_options['style_options']['info'] = array(
	  'name' => array(
		'sortable' => 1,
		'default_sort_order' => 'asc',
		'align' => '',
		'separator' => '',
		'empty_column' => 0,
	  ),
	  'name_1' => array(
		'sortable' => 1,
		'default_sort_order' => 'desc',
		'align' => 'views-align-right',
		'separator' => '',
		'empty_column' => 0,
	  ),
	);
	/* Header: Global: Text area */
	$handler->display->display_options['header']['area']['id'] = 'area';
	$handler->display->display_options['header']['area']['table'] = 'views';
	$handler->display->display_options['header']['area']['field'] = 'area';
	/* Relationship: Recruitment: Added By */
	$handler->display->display_options['relationships']['added_by']['id'] = 'added_by';
	$handler->display->display_options['relationships']['added_by']['table'] = 'eve_recruitment';
	$handler->display->display_options['relationships']['added_by']['field'] = 'added_by';
	/* Relationship: Recruitment: Mailed By */
	$handler->display->display_options['relationships']['mailed_by']['id'] = 'mailed_by';
	$handler->display->display_options['relationships']['mailed_by']['table'] = 'eve_recruitment';
	$handler->display->display_options['relationships']['mailed_by']['field'] = 'mailed_by';
	/* Field: User: Name */
	$handler->display->display_options['fields']['name']['id'] = 'name';
	$handler->display->display_options['fields']['name']['table'] = 'users';
	$handler->display->display_options['fields']['name']['field'] = 'name';
	$handler->display->display_options['fields']['name']['relationship'] = 'added_by';
	$handler->display->display_options['fields']['name']['label'] = 'Recruiter Name';
	/* Field: COUNT(User: Name) */
	$handler->display->display_options['fields']['name_1']['id'] = 'name_1';
	$handler->display->display_options['fields']['name_1']['table'] = 'users';
	$handler->display->display_options['fields']['name_1']['field'] = 'name';
	$handler->display->display_options['fields']['name_1']['relationship'] = 'added_by';
	$handler->display->display_options['fields']['name_1']['group_type'] = 'count';
	$handler->display->display_options['fields']['name_1']['label'] = 'Names Contributed';
	$handler->display->display_options['fields']['name_1']['separator'] = ' ';
	/* Field: COUNT(Recruitment: Date Added) */
	$handler->display->display_options['fields']['added_date']['id'] = 'added_date';
	$handler->display->display_options['fields']['added_date']['table'] = 'eve_recruitment';
	$handler->display->display_options['fields']['added_date']['field'] = 'added_date';
	$handler->display->display_options['fields']['added_date']['group_type'] = 'count';
	/* Sort criterion: COUNT(Recruitment: Date Mailed) */
	$handler->display->display_options['sorts']['mailed_date']['id'] = 'mailed_date';
	$handler->display->display_options['sorts']['mailed_date']['table'] = 'eve_recruitment';
	$handler->display->display_options['sorts']['mailed_date']['field'] = 'mailed_date';
	$handler->display->display_options['sorts']['mailed_date']['group_type'] = 'count';
	$handler->display->display_options['sorts']['mailed_date']['order'] = 'DESC';
	/* Filter criterion: Recruitment: Imported */
	$handler->display->display_options['filters']['imported']['id'] = 'imported';
	$handler->display->display_options['filters']['imported']['table'] = 'eve_recruitment';
	$handler->display->display_options['filters']['imported']['field'] = 'imported';
	$handler->display->display_options['filters']['imported']['value'] = '0';

	/* Display: Recruitment Summary */
	$handler = $view->new_display('page', 'Recruitment Summary', 'recruitment_summary');
	$handler->display->display_options['defaults']['style_plugin'] = FALSE;
	$handler->display->display_options['style_plugin'] = 'list';
	$handler->display->display_options['defaults']['style_options'] = FALSE;
	$handler->display->display_options['defaults']['row_plugin'] = FALSE;
	$handler->display->display_options['row_plugin'] = 'fields';
	$handler->display->display_options['row_options']['inline'] = array(
	  'name' => 'name',
	  'added_date' => 'added_date',
	);
	$handler->display->display_options['row_options']['separator'] = ':';
	$handler->display->display_options['defaults']['row_options'] = FALSE;
	$handler->display->display_options['defaults']['header'] = FALSE;
	/* Header: Global: Text area */
	$handler->display->display_options['header']['area']['id'] = 'area';
	$handler->display->display_options['header']['area']['table'] = 'views';
	$handler->display->display_options['header']['area']['field'] = 'area';
	$handler->display->display_options['header']['area']['label'] = 'Names Contributed';
	$handler->display->display_options['header']['area']['content'] = '<h3>Names Contributed</h3>';
	$handler->display->display_options['header']['area']['format'] = 'full_html';
	$handler->display->display_options['defaults']['fields'] = FALSE;
	/* Field: User: Name */
	$handler->display->display_options['fields']['name']['id'] = 'name';
	$handler->display->display_options['fields']['name']['table'] = 'users';
	$handler->display->display_options['fields']['name']['field'] = 'name';
	$handler->display->display_options['fields']['name']['relationship'] = 'added_by';
	$handler->display->display_options['fields']['name']['label'] = '';
	$handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
	/* Field: COUNT(Recruitment: Date Added) */
	$handler->display->display_options['fields']['added_date']['id'] = 'added_date';
	$handler->display->display_options['fields']['added_date']['table'] = 'eve_recruitment';
	$handler->display->display_options['fields']['added_date']['field'] = 'added_date';
	$handler->display->display_options['fields']['added_date']['group_type'] = 'count';
	$handler->display->display_options['fields']['added_date']['label'] = '';
	$handler->display->display_options['fields']['added_date']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['added_date']['separator'] = '';
	$handler->display->display_options['defaults']['sorts'] = FALSE;
	/* Sort criterion: COUNT(Recruitment: Date Added) */
	$handler->display->display_options['sorts']['added_date']['id'] = 'added_date';
	$handler->display->display_options['sorts']['added_date']['table'] = 'eve_recruitment';
	$handler->display->display_options['sorts']['added_date']['field'] = 'added_date';
	$handler->display->display_options['sorts']['added_date']['group_type'] = 'count';
	$handler->display->display_options['sorts']['added_date']['order'] = 'DESC';
	$handler->display->display_options['path'] = 'recruitment/summary';

	/* Display: Mailing Summary */
	$handler = $view->new_display('attachment', 'Mailing Summary', 'mailing_summary');
	$handler->display->display_options['defaults']['title'] = FALSE;
	$handler->display->display_options['pager']['type'] = 'none';
	$handler->display->display_options['pager']['options']['offset'] = '0';
	$handler->display->display_options['defaults']['style_plugin'] = FALSE;
	$handler->display->display_options['style_plugin'] = 'list';
	$handler->display->display_options['defaults']['style_options'] = FALSE;
	$handler->display->display_options['defaults']['row_plugin'] = FALSE;
	$handler->display->display_options['row_plugin'] = 'fields';
	$handler->display->display_options['row_options']['inline'] = array(
	  'name' => 'name',
	  'mailed_date' => 'mailed_date',
	);
	$handler->display->display_options['row_options']['separator'] = ':';
	$handler->display->display_options['defaults']['row_options'] = FALSE;
	$handler->display->display_options['defaults']['header'] = FALSE;
	/* Header: Global: Text area */
	$handler->display->display_options['header']['area']['id'] = 'area';
	$handler->display->display_options['header']['area']['table'] = 'views';
	$handler->display->display_options['header']['area']['field'] = 'area';
	$handler->display->display_options['header']['area']['label'] = 'Characters Mailed';
	$handler->display->display_options['header']['area']['content'] = '<h3>Characters Mailed</h3>';
	$handler->display->display_options['header']['area']['format'] = 'full_html';
	$handler->display->display_options['defaults']['fields'] = FALSE;
	/* Field: User: Name */
	$handler->display->display_options['fields']['name']['id'] = 'name';
	$handler->display->display_options['fields']['name']['table'] = 'users';
	$handler->display->display_options['fields']['name']['field'] = 'name';
	$handler->display->display_options['fields']['name']['relationship'] = 'mailed_by';
	$handler->display->display_options['fields']['name']['label'] = '';
	$handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
	/* Field: COUNT(Recruitment: Date Mailed) */
	$handler->display->display_options['fields']['mailed_date']['id'] = 'mailed_date';
	$handler->display->display_options['fields']['mailed_date']['table'] = 'eve_recruitment';
	$handler->display->display_options['fields']['mailed_date']['field'] = 'mailed_date';
	$handler->display->display_options['fields']['mailed_date']['group_type'] = 'count';
	$handler->display->display_options['fields']['mailed_date']['label'] = '';
	$handler->display->display_options['fields']['mailed_date']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['mailed_date']['separator'] = ' ';
	$handler->display->display_options['defaults']['filter_groups'] = FALSE;
	$handler->display->display_options['defaults']['filters'] = FALSE;
	/* Filter criterion: Recruitment: Date Mailed */
	$handler->display->display_options['filters']['mailed_date']['id'] = 'mailed_date';
	$handler->display->display_options['filters']['mailed_date']['table'] = 'eve_recruitment';
	$handler->display->display_options['filters']['mailed_date']['field'] = 'mailed_date';
	$handler->display->display_options['filters']['mailed_date']['operator'] = 'not empty';
	/* Filter criterion: Recruitment: Imported */
	$handler->display->display_options['filters']['imported']['id'] = 'imported';
	$handler->display->display_options['filters']['imported']['table'] = 'eve_recruitment';
	$handler->display->display_options['filters']['imported']['field'] = 'imported';
	$handler->display->display_options['filters']['imported']['value'] = '0';
	$handler->display->display_options['displays'] = array(
	  'recruitment_summary' => 'recruitment_summary',
	  'default' => 0,
	);
	$handler->display->display_options['attachment_position'] = 'after';

	/* Display: Import Summary */
	$handler = $view->new_display('attachment', 'Import Summary', 'attachment_1');
	$handler->display->display_options['defaults']['title'] = FALSE;
	$handler->display->display_options['pager']['type'] = 'some';
	$handler->display->display_options['defaults']['style_plugin'] = FALSE;
	$handler->display->display_options['style_plugin'] = 'default';
	$handler->display->display_options['defaults']['style_options'] = FALSE;
	$handler->display->display_options['defaults']['row_plugin'] = FALSE;
	$handler->display->display_options['row_plugin'] = 'fields';
	$handler->display->display_options['defaults']['row_options'] = FALSE;
	$handler->display->display_options['defaults']['header'] = FALSE;
	/* Header: Global: Text area */
	$handler->display->display_options['header']['area']['id'] = 'area';
	$handler->display->display_options['header']['area']['table'] = 'views';
	$handler->display->display_options['header']['area']['field'] = 'area';
	$handler->display->display_options['header']['area']['label'] = 'Other';
	$handler->display->display_options['header']['area']['content'] = '<h3>Other</h3>';
	$handler->display->display_options['header']['area']['format'] = 'full_html';
	$handler->display->display_options['defaults']['fields'] = FALSE;
	/* Field: COUNT(Recruitment: Date Added) */
	$handler->display->display_options['fields']['added_date']['id'] = 'added_date';
	$handler->display->display_options['fields']['added_date']['table'] = 'eve_recruitment';
	$handler->display->display_options['fields']['added_date']['field'] = 'added_date';
	$handler->display->display_options['fields']['added_date']['group_type'] = 'count';
	$handler->display->display_options['fields']['added_date']['label'] = 'Names Imported';
	$handler->display->display_options['fields']['added_date']['separator'] = ' ';
	$handler->display->display_options['defaults']['filter_groups'] = FALSE;
	$handler->display->display_options['defaults']['filters'] = FALSE;
	/* Filter criterion: Recruitment: Imported */
	$handler->display->display_options['filters']['imported']['id'] = 'imported';
	$handler->display->display_options['filters']['imported']['table'] = 'eve_recruitment';
	$handler->display->display_options['filters']['imported']['field'] = 'imported';
	$handler->display->display_options['filters']['imported']['value'] = '1';
	$handler->display->display_options['displays'] = array(
	  'recruitment_summary' => 'recruitment_summary',
	  'default' => 0,
	);
	$handler->display->display_options['attachment_position'] = 'after';
	$views[$view->name] = $view;
	
	// Monthly Summary
	$view = new view();
	$view->name = 'monthly_recruitment_statistics';
	$view->description = '';
	$view->tag = 'default';
	$view->base_table = 'eve_recruitment';
	$view->human_name = 'Monthly Recruitment Statistics';
	$view->core = 7;
	$view->api_version = '3.0';
	$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

	/* Display: Master */
	$handler = $view->new_display('default', 'Master', 'default');
	$handler->display->display_options['title'] = 'Monthly Recruitment Summary';
	$handler->display->display_options['use_more_always'] = FALSE;
	$handler->display->display_options['group_by'] = TRUE;
	$handler->display->display_options['access']['type'] = 'perm';
	$handler->display->display_options['access']['perm'] = 'view statistics';
	$handler->display->display_options['cache']['type'] = 'none';
	$handler->display->display_options['query']['type'] = 'views_query';
	$handler->display->display_options['exposed_form']['type'] = 'basic';
	$handler->display->display_options['pager']['type'] = 'mini';
	$handler->display->display_options['pager']['options']['items_per_page'] = '10';
	$handler->display->display_options['pager']['options']['offset'] = '0';
	$handler->display->display_options['pager']['options']['id'] = '0';
	$handler->display->display_options['style_plugin'] = 'table';
	$handler->display->display_options['style_options']['columns'] = array(
	  'name' => 'name',
	  'name_1' => 'name_1',
	);
	$handler->display->display_options['style_options']['default'] = 'name_1';
	$handler->display->display_options['style_options']['info'] = array(
	  'name' => array(
		'sortable' => 1,
		'default_sort_order' => 'asc',
		'align' => '',
		'separator' => '',
		'empty_column' => 0,
	  ),
	  'name_1' => array(
		'sortable' => 1,
		'default_sort_order' => 'desc',
		'align' => 'views-align-right',
		'separator' => '',
		'empty_column' => 0,
	  ),
	);
	/* Header: Global: Text area */
	$handler->display->display_options['header']['area']['id'] = 'area';
	$handler->display->display_options['header']['area']['table'] = 'views';
	$handler->display->display_options['header']['area']['field'] = 'area';
	/* Relationship: Recruitment: Added By */
	$handler->display->display_options['relationships']['added_by']['id'] = 'added_by';
	$handler->display->display_options['relationships']['added_by']['table'] = 'eve_recruitment';
	$handler->display->display_options['relationships']['added_by']['field'] = 'added_by';
	/* Relationship: Recruitment: Mailed By */
	$handler->display->display_options['relationships']['mailed_by']['id'] = 'mailed_by';
	$handler->display->display_options['relationships']['mailed_by']['table'] = 'eve_recruitment';
	$handler->display->display_options['relationships']['mailed_by']['field'] = 'mailed_by';
	/* Field: COUNT(Recruitment: Date Added) */
	$handler->display->display_options['fields']['added_date']['id'] = 'added_date';
	$handler->display->display_options['fields']['added_date']['table'] = 'eve_recruitment';
	$handler->display->display_options['fields']['added_date']['field'] = 'added_date';
	$handler->display->display_options['fields']['added_date']['group_type'] = 'count';
	/* Sort criterion: COUNT(Recruitment: Date Mailed) */
	$handler->display->display_options['sorts']['mailed_date']['id'] = 'mailed_date';
	$handler->display->display_options['sorts']['mailed_date']['table'] = 'eve_recruitment';
	$handler->display->display_options['sorts']['mailed_date']['field'] = 'mailed_date';
	$handler->display->display_options['sorts']['mailed_date']['group_type'] = 'count';
	$handler->display->display_options['sorts']['mailed_date']['order'] = 'DESC';
	/* Filter criterion: Recruitment: Imported */
	$handler->display->display_options['filters']['imported']['id'] = 'imported';
	$handler->display->display_options['filters']['imported']['table'] = 'eve_recruitment';
	$handler->display->display_options['filters']['imported']['field'] = 'imported';
	$handler->display->display_options['filters']['imported']['value'] = '0';
	/* Filter criterion: Recruitment: Date Added */
	$handler->display->display_options['filters']['added_date']['id'] = 'added_date';
	$handler->display->display_options['filters']['added_date']['table'] = 'eve_recruitment';
	$handler->display->display_options['filters']['added_date']['field'] = 'added_date';
	$handler->display->display_options['filters']['added_date']['operator'] = '>=';
	$handler->display->display_options['filters']['added_date']['value']['value'] = '-30 days';
	$handler->display->display_options['filters']['added_date']['value']['type'] = 'offset';

	/* Display: Waiting */
	$handler = $view->new_display('attachment', 'Waiting', 'attachment_2');
	$handler->display->display_options['defaults']['title'] = FALSE;
	$handler->display->display_options['pager']['type'] = 'some';
	$handler->display->display_options['defaults']['style_plugin'] = FALSE;
	$handler->display->display_options['style_plugin'] = 'default';
	$handler->display->display_options['defaults']['style_options'] = FALSE;
	$handler->display->display_options['defaults']['row_plugin'] = FALSE;
	$handler->display->display_options['row_plugin'] = 'fields';
	$handler->display->display_options['defaults']['row_options'] = FALSE;
	$handler->display->display_options['defaults']['header'] = FALSE;
	/* Header: Global: Text area */
	$handler->display->display_options['header']['area']['id'] = 'area';
	$handler->display->display_options['header']['area']['table'] = 'views';
	$handler->display->display_options['header']['area']['field'] = 'area';
	$handler->display->display_options['header']['area']['label'] = 'Waiting';
	$handler->display->display_options['header']['area']['content'] = '<h3>Mails To Be Sent</h3>';
	$handler->display->display_options['header']['area']['format'] = 'full_html';
	$handler->display->display_options['defaults']['fields'] = FALSE;
	/* Field: COUNT(Recruitment: Date Added) */
	$handler->display->display_options['fields']['added_date']['id'] = 'added_date';
	$handler->display->display_options['fields']['added_date']['table'] = 'eve_recruitment';
	$handler->display->display_options['fields']['added_date']['field'] = 'added_date';
	$handler->display->display_options['fields']['added_date']['group_type'] = 'count';
	$handler->display->display_options['fields']['added_date']['label'] = 'Names';
	$handler->display->display_options['fields']['added_date']['separator'] = ' ';
	$handler->display->display_options['defaults']['sorts'] = FALSE;
	$handler->display->display_options['defaults']['filter_groups'] = FALSE;
	$handler->display->display_options['defaults']['filters'] = FALSE;
	/* Filter criterion: Recruitment: Imported */
	$handler->display->display_options['filters']['imported']['id'] = 'imported';
	$handler->display->display_options['filters']['imported']['table'] = 'eve_recruitment';
	$handler->display->display_options['filters']['imported']['field'] = 'imported';
	$handler->display->display_options['filters']['imported']['value'] = '0';
	/* Filter criterion: Recruitment: Date Mailed */
	$handler->display->display_options['filters']['mailed_date']['id'] = 'mailed_date';
	$handler->display->display_options['filters']['mailed_date']['table'] = 'eve_recruitment';
	$handler->display->display_options['filters']['mailed_date']['field'] = 'mailed_date';
	$handler->display->display_options['filters']['mailed_date']['operator'] = 'empty';
	$handler->display->display_options['displays'] = array(
	  'recruitment_summary' => 'recruitment_summary',
	  'default' => 0,
	);
	$handler->display->display_options['attachment_position'] = 'after';

	/* Display: Recruitment Summary */
	$handler = $view->new_display('page', 'Recruitment Summary', 'recruitment_summary');
	$handler->display->display_options['defaults']['style_plugin'] = FALSE;
	$handler->display->display_options['style_plugin'] = 'list';
	$handler->display->display_options['defaults']['style_options'] = FALSE;
	$handler->display->display_options['defaults']['row_plugin'] = FALSE;
	$handler->display->display_options['row_plugin'] = 'fields';
	$handler->display->display_options['row_options']['inline'] = array(
	  'name' => 'name',
	  'added_date' => 'added_date',
	);
	$handler->display->display_options['row_options']['separator'] = ':';
	$handler->display->display_options['defaults']['row_options'] = FALSE;
	$handler->display->display_options['defaults']['header'] = FALSE;
	/* Header: Global: Text area */
	$handler->display->display_options['header']['area']['id'] = 'area';
	$handler->display->display_options['header']['area']['table'] = 'views';
	$handler->display->display_options['header']['area']['field'] = 'area';
	$handler->display->display_options['header']['area']['label'] = 'Names Contributed';
	$handler->display->display_options['header']['area']['content'] = '<h3>Names Contributed</h3>';
	$handler->display->display_options['header']['area']['format'] = 'full_html';
	$handler->display->display_options['defaults']['fields'] = FALSE;
	/* Field: User: Name */
	$handler->display->display_options['fields']['name']['id'] = 'name';
	$handler->display->display_options['fields']['name']['table'] = 'users';
	$handler->display->display_options['fields']['name']['field'] = 'name';
	$handler->display->display_options['fields']['name']['relationship'] = 'added_by';
	$handler->display->display_options['fields']['name']['label'] = '';
	$handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
	/* Field: COUNT(Recruitment: Date Added) */
	$handler->display->display_options['fields']['added_date']['id'] = 'added_date';
	$handler->display->display_options['fields']['added_date']['table'] = 'eve_recruitment';
	$handler->display->display_options['fields']['added_date']['field'] = 'added_date';
	$handler->display->display_options['fields']['added_date']['group_type'] = 'count';
	$handler->display->display_options['fields']['added_date']['label'] = '';
	$handler->display->display_options['fields']['added_date']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['added_date']['separator'] = '';
	$handler->display->display_options['defaults']['sorts'] = FALSE;
	/* Sort criterion: COUNT(Recruitment: Date Added) */
	$handler->display->display_options['sorts']['added_date']['id'] = 'added_date';
	$handler->display->display_options['sorts']['added_date']['table'] = 'eve_recruitment';
	$handler->display->display_options['sorts']['added_date']['field'] = 'added_date';
	$handler->display->display_options['sorts']['added_date']['group_type'] = 'count';
	$handler->display->display_options['sorts']['added_date']['order'] = 'DESC';
	$handler->display->display_options['path'] = 'recruitment/summary/monthly';

	/* Display: Mailing Summary */
	$handler = $view->new_display('attachment', 'Mailing Summary', 'mailing_summary');
	$handler->display->display_options['defaults']['title'] = FALSE;
	$handler->display->display_options['pager']['type'] = 'none';
	$handler->display->display_options['pager']['options']['offset'] = '0';
	$handler->display->display_options['defaults']['style_plugin'] = FALSE;
	$handler->display->display_options['style_plugin'] = 'list';
	$handler->display->display_options['defaults']['style_options'] = FALSE;
	$handler->display->display_options['defaults']['row_plugin'] = FALSE;
	$handler->display->display_options['row_plugin'] = 'fields';
	$handler->display->display_options['row_options']['inline'] = array(
	  'name' => 'name',
	  'mailed_date' => 'mailed_date',
	);
	$handler->display->display_options['row_options']['separator'] = ':';
	$handler->display->display_options['defaults']['row_options'] = FALSE;
	$handler->display->display_options['defaults']['header'] = FALSE;
	/* Header: Global: Text area */
	$handler->display->display_options['header']['area']['id'] = 'area';
	$handler->display->display_options['header']['area']['table'] = 'views';
	$handler->display->display_options['header']['area']['field'] = 'area';
	$handler->display->display_options['header']['area']['label'] = 'Characters Mailed';
	$handler->display->display_options['header']['area']['content'] = '<h3>Characters Mailed</h3>';
	$handler->display->display_options['header']['area']['format'] = 'full_html';
	$handler->display->display_options['defaults']['fields'] = FALSE;
	/* Field: User: Name */
	$handler->display->display_options['fields']['name']['id'] = 'name';
	$handler->display->display_options['fields']['name']['table'] = 'users';
	$handler->display->display_options['fields']['name']['field'] = 'name';
	$handler->display->display_options['fields']['name']['relationship'] = 'mailed_by';
	$handler->display->display_options['fields']['name']['label'] = '';
	$handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
	/* Field: COUNT(Recruitment: Date Mailed) */
	$handler->display->display_options['fields']['mailed_date']['id'] = 'mailed_date';
	$handler->display->display_options['fields']['mailed_date']['table'] = 'eve_recruitment';
	$handler->display->display_options['fields']['mailed_date']['field'] = 'mailed_date';
	$handler->display->display_options['fields']['mailed_date']['group_type'] = 'count';
	$handler->display->display_options['fields']['mailed_date']['label'] = '';
	$handler->display->display_options['fields']['mailed_date']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['mailed_date']['separator'] = ' ';
	$handler->display->display_options['defaults']['sorts'] = FALSE;
	/* Sort criterion: COUNT(Recruitment: Date Mailed) */
	$handler->display->display_options['sorts']['mailed_date']['id'] = 'mailed_date';
	$handler->display->display_options['sorts']['mailed_date']['table'] = 'eve_recruitment';
	$handler->display->display_options['sorts']['mailed_date']['field'] = 'mailed_date';
	$handler->display->display_options['sorts']['mailed_date']['group_type'] = 'count';
	$handler->display->display_options['sorts']['mailed_date']['order'] = 'DESC';
	$handler->display->display_options['defaults']['filter_groups'] = FALSE;
	$handler->display->display_options['defaults']['filters'] = FALSE;
	/* Filter criterion: Recruitment: Date Mailed */
	$handler->display->display_options['filters']['mailed_date']['id'] = 'mailed_date';
	$handler->display->display_options['filters']['mailed_date']['table'] = 'eve_recruitment';
	$handler->display->display_options['filters']['mailed_date']['field'] = 'mailed_date';
	$handler->display->display_options['filters']['mailed_date']['operator'] = '>=';
	$handler->display->display_options['filters']['mailed_date']['value']['value'] = '-30 days';
	$handler->display->display_options['filters']['mailed_date']['value']['type'] = 'offset';
	/* Filter criterion: Recruitment: Imported */
	$handler->display->display_options['filters']['imported']['id'] = 'imported';
	$handler->display->display_options['filters']['imported']['table'] = 'eve_recruitment';
	$handler->display->display_options['filters']['imported']['field'] = 'imported';
	$handler->display->display_options['filters']['imported']['value'] = '0';
	$handler->display->display_options['displays'] = array(
	  'recruitment_summary' => 'recruitment_summary',
	  'default' => 0,
	);
	$handler->display->display_options['attachment_position'] = 'after';
	$views[$view->name] = $view;

	// Weekly Summary
	$view = new view();
	$view->name = 'weekly_recruitment_statistics';
	$view->description = '';
	$view->tag = 'default';
	$view->base_table = 'eve_recruitment';
	$view->human_name = 'Weekly Recruitment Statistics';
	$view->core = 7;
	$view->api_version = '3.0';
	$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

	/* Display: Master */
	$handler = $view->new_display('default', 'Master', 'default');
	$handler->display->display_options['title'] = 'Weekly Recruitment Summary';
	$handler->display->display_options['use_more_always'] = FALSE;
	$handler->display->display_options['group_by'] = TRUE;
	$handler->display->display_options['access']['type'] = 'perm';
	$handler->display->display_options['access']['perm'] = 'view statistics';
	$handler->display->display_options['cache']['type'] = 'none';
	$handler->display->display_options['query']['type'] = 'views_query';
	$handler->display->display_options['exposed_form']['type'] = 'basic';
	$handler->display->display_options['pager']['type'] = 'mini';
	$handler->display->display_options['pager']['options']['items_per_page'] = '10';
	$handler->display->display_options['pager']['options']['offset'] = '0';
	$handler->display->display_options['pager']['options']['id'] = '0';
	$handler->display->display_options['style_plugin'] = 'table';
	$handler->display->display_options['style_options']['columns'] = array(
	  'name' => 'name',
	  'name_1' => 'name_1',
	);
	$handler->display->display_options['style_options']['default'] = 'name_1';
	$handler->display->display_options['style_options']['info'] = array(
	  'name' => array(
		'sortable' => 1,
		'default_sort_order' => 'asc',
		'align' => '',
		'separator' => '',
		'empty_column' => 0,
	  ),
	  'name_1' => array(
		'sortable' => 1,
		'default_sort_order' => 'desc',
		'align' => 'views-align-right',
		'separator' => '',
		'empty_column' => 0,
	  ),
	);
	/* Header: Global: Text area */
	$handler->display->display_options['header']['area']['id'] = 'area';
	$handler->display->display_options['header']['area']['table'] = 'views';
	$handler->display->display_options['header']['area']['field'] = 'area';
	/* Relationship: Recruitment: Added By */
	$handler->display->display_options['relationships']['added_by']['id'] = 'added_by';
	$handler->display->display_options['relationships']['added_by']['table'] = 'eve_recruitment';
	$handler->display->display_options['relationships']['added_by']['field'] = 'added_by';
	/* Relationship: Recruitment: Mailed By */
	$handler->display->display_options['relationships']['mailed_by']['id'] = 'mailed_by';
	$handler->display->display_options['relationships']['mailed_by']['table'] = 'eve_recruitment';
	$handler->display->display_options['relationships']['mailed_by']['field'] = 'mailed_by';
	/* Field: COUNT(Recruitment: Date Added) */
	$handler->display->display_options['fields']['added_date']['id'] = 'added_date';
	$handler->display->display_options['fields']['added_date']['table'] = 'eve_recruitment';
	$handler->display->display_options['fields']['added_date']['field'] = 'added_date';
	$handler->display->display_options['fields']['added_date']['group_type'] = 'count';
	/* Sort criterion: COUNT(Recruitment: Date Mailed) */
	$handler->display->display_options['sorts']['mailed_date']['id'] = 'mailed_date';
	$handler->display->display_options['sorts']['mailed_date']['table'] = 'eve_recruitment';
	$handler->display->display_options['sorts']['mailed_date']['field'] = 'mailed_date';
	$handler->display->display_options['sorts']['mailed_date']['group_type'] = 'count';
	$handler->display->display_options['sorts']['mailed_date']['order'] = 'DESC';
	/* Filter criterion: Recruitment: Imported */
	$handler->display->display_options['filters']['imported']['id'] = 'imported';
	$handler->display->display_options['filters']['imported']['table'] = 'eve_recruitment';
	$handler->display->display_options['filters']['imported']['field'] = 'imported';
	$handler->display->display_options['filters']['imported']['value'] = '0';
	/* Filter criterion: Recruitment: Date Added */
	$handler->display->display_options['filters']['added_date']['id'] = 'added_date';
	$handler->display->display_options['filters']['added_date']['table'] = 'eve_recruitment';
	$handler->display->display_options['filters']['added_date']['field'] = 'added_date';
	$handler->display->display_options['filters']['added_date']['operator'] = '>=';
	$handler->display->display_options['filters']['added_date']['value']['value'] = '-7 days';
	$handler->display->display_options['filters']['added_date']['value']['type'] = 'offset';

	/* Display: Waiting */
	$handler = $view->new_display('attachment', 'Waiting', 'attachment_2');
	$handler->display->display_options['defaults']['title'] = FALSE;
	$handler->display->display_options['pager']['type'] = 'some';
	$handler->display->display_options['defaults']['style_plugin'] = FALSE;
	$handler->display->display_options['style_plugin'] = 'default';
	$handler->display->display_options['defaults']['style_options'] = FALSE;
	$handler->display->display_options['defaults']['row_plugin'] = FALSE;
	$handler->display->display_options['row_plugin'] = 'fields';
	$handler->display->display_options['defaults']['row_options'] = FALSE;
	$handler->display->display_options['defaults']['header'] = FALSE;
	/* Header: Global: Text area */
	$handler->display->display_options['header']['area']['id'] = 'area';
	$handler->display->display_options['header']['area']['table'] = 'views';
	$handler->display->display_options['header']['area']['field'] = 'area';
	$handler->display->display_options['header']['area']['label'] = 'Waiting';
	$handler->display->display_options['header']['area']['content'] = '<h3>Mails To Be Sent</h3>';
	$handler->display->display_options['header']['area']['format'] = 'full_html';
	$handler->display->display_options['defaults']['fields'] = FALSE;
	/* Field: COUNT(Recruitment: Date Added) */
	$handler->display->display_options['fields']['added_date']['id'] = 'added_date';
	$handler->display->display_options['fields']['added_date']['table'] = 'eve_recruitment';
	$handler->display->display_options['fields']['added_date']['field'] = 'added_date';
	$handler->display->display_options['fields']['added_date']['group_type'] = 'count';
	$handler->display->display_options['fields']['added_date']['label'] = 'Names';
	$handler->display->display_options['fields']['added_date']['separator'] = ' ';
	$handler->display->display_options['defaults']['sorts'] = FALSE;
	$handler->display->display_options['defaults']['filter_groups'] = FALSE;
	$handler->display->display_options['defaults']['filters'] = FALSE;
	/* Filter criterion: Recruitment: Imported */
	$handler->display->display_options['filters']['imported']['id'] = 'imported';
	$handler->display->display_options['filters']['imported']['table'] = 'eve_recruitment';
	$handler->display->display_options['filters']['imported']['field'] = 'imported';
	$handler->display->display_options['filters']['imported']['value'] = '0';
	/* Filter criterion: Recruitment: Date Mailed */
	$handler->display->display_options['filters']['mailed_date']['id'] = 'mailed_date';
	$handler->display->display_options['filters']['mailed_date']['table'] = 'eve_recruitment';
	$handler->display->display_options['filters']['mailed_date']['field'] = 'mailed_date';
	$handler->display->display_options['filters']['mailed_date']['operator'] = 'empty';
	$handler->display->display_options['displays'] = array(
	  'recruitment_summary' => 'recruitment_summary',
	  'default' => 0,
	);
	$handler->display->display_options['attachment_position'] = 'after';

	/* Display: Recruitment Summary */
	$handler = $view->new_display('page', 'Recruitment Summary', 'recruitment_summary');
	$handler->display->display_options['defaults']['style_plugin'] = FALSE;
	$handler->display->display_options['style_plugin'] = 'list';
	$handler->display->display_options['defaults']['style_options'] = FALSE;
	$handler->display->display_options['defaults']['row_plugin'] = FALSE;
	$handler->display->display_options['row_plugin'] = 'fields';
	$handler->display->display_options['row_options']['inline'] = array(
	  'name' => 'name',
	  'added_date' => 'added_date',
	);
	$handler->display->display_options['row_options']['separator'] = ':';
	$handler->display->display_options['defaults']['row_options'] = FALSE;
	$handler->display->display_options['defaults']['header'] = FALSE;
	/* Header: Global: Text area */
	$handler->display->display_options['header']['area']['id'] = 'area';
	$handler->display->display_options['header']['area']['table'] = 'views';
	$handler->display->display_options['header']['area']['field'] = 'area';
	$handler->display->display_options['header']['area']['label'] = 'Names Contributed';
	$handler->display->display_options['header']['area']['content'] = '<h3>Names Contributed</h3>';
	$handler->display->display_options['header']['area']['format'] = 'full_html';
	$handler->display->display_options['defaults']['fields'] = FALSE;
	/* Field: User: Name */
	$handler->display->display_options['fields']['name']['id'] = 'name';
	$handler->display->display_options['fields']['name']['table'] = 'users';
	$handler->display->display_options['fields']['name']['field'] = 'name';
	$handler->display->display_options['fields']['name']['relationship'] = 'added_by';
	$handler->display->display_options['fields']['name']['label'] = '';
	$handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
	/* Field: COUNT(Recruitment: Date Added) */
	$handler->display->display_options['fields']['added_date']['id'] = 'added_date';
	$handler->display->display_options['fields']['added_date']['table'] = 'eve_recruitment';
	$handler->display->display_options['fields']['added_date']['field'] = 'added_date';
	$handler->display->display_options['fields']['added_date']['group_type'] = 'count';
	$handler->display->display_options['fields']['added_date']['label'] = '';
	$handler->display->display_options['fields']['added_date']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['added_date']['separator'] = '';
	$handler->display->display_options['defaults']['sorts'] = FALSE;
	/* Sort criterion: COUNT(Recruitment: Date Added) */
	$handler->display->display_options['sorts']['added_date']['id'] = 'added_date';
	$handler->display->display_options['sorts']['added_date']['table'] = 'eve_recruitment';
	$handler->display->display_options['sorts']['added_date']['field'] = 'added_date';
	$handler->display->display_options['sorts']['added_date']['group_type'] = 'count';
	$handler->display->display_options['sorts']['added_date']['order'] = 'DESC';
	$handler->display->display_options['path'] = 'recruitment/summary/weekly';

	/* Display: Mailing Summary */
	$handler = $view->new_display('attachment', 'Mailing Summary', 'mailing_summary');
	$handler->display->display_options['defaults']['title'] = FALSE;
	$handler->display->display_options['pager']['type'] = 'none';
	$handler->display->display_options['pager']['options']['offset'] = '0';
	$handler->display->display_options['defaults']['style_plugin'] = FALSE;
	$handler->display->display_options['style_plugin'] = 'list';
	$handler->display->display_options['defaults']['style_options'] = FALSE;
	$handler->display->display_options['defaults']['row_plugin'] = FALSE;
	$handler->display->display_options['row_plugin'] = 'fields';
	$handler->display->display_options['row_options']['inline'] = array(
	  'name' => 'name',
	  'mailed_date' => 'mailed_date',
	);
	$handler->display->display_options['row_options']['separator'] = ':';
	$handler->display->display_options['defaults']['row_options'] = FALSE;
	$handler->display->display_options['defaults']['header'] = FALSE;
	/* Header: Global: Text area */
	$handler->display->display_options['header']['area']['id'] = 'area';
	$handler->display->display_options['header']['area']['table'] = 'views';
	$handler->display->display_options['header']['area']['field'] = 'area';
	$handler->display->display_options['header']['area']['label'] = 'Characters Mailed';
	$handler->display->display_options['header']['area']['content'] = '<h3>Characters Mailed</h3>';
	$handler->display->display_options['header']['area']['format'] = 'full_html';
	$handler->display->display_options['defaults']['fields'] = FALSE;
	/* Field: User: Name */
	$handler->display->display_options['fields']['name']['id'] = 'name';
	$handler->display->display_options['fields']['name']['table'] = 'users';
	$handler->display->display_options['fields']['name']['field'] = 'name';
	$handler->display->display_options['fields']['name']['relationship'] = 'mailed_by';
	$handler->display->display_options['fields']['name']['label'] = '';
	$handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
	/* Field: COUNT(Recruitment: Date Mailed) */
	$handler->display->display_options['fields']['mailed_date']['id'] = 'mailed_date';
	$handler->display->display_options['fields']['mailed_date']['table'] = 'eve_recruitment';
	$handler->display->display_options['fields']['mailed_date']['field'] = 'mailed_date';
	$handler->display->display_options['fields']['mailed_date']['group_type'] = 'count';
	$handler->display->display_options['fields']['mailed_date']['label'] = '';
	$handler->display->display_options['fields']['mailed_date']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['mailed_date']['separator'] = ' ';
	$handler->display->display_options['defaults']['sorts'] = FALSE;
	/* Sort criterion: COUNT(Recruitment: Date Mailed) */
	$handler->display->display_options['sorts']['mailed_date']['id'] = 'mailed_date';
	$handler->display->display_options['sorts']['mailed_date']['table'] = 'eve_recruitment';
	$handler->display->display_options['sorts']['mailed_date']['field'] = 'mailed_date';
	$handler->display->display_options['sorts']['mailed_date']['group_type'] = 'count';
	$handler->display->display_options['sorts']['mailed_date']['order'] = 'DESC';
	$handler->display->display_options['defaults']['filter_groups'] = FALSE;
	$handler->display->display_options['defaults']['filters'] = FALSE;
	/* Filter criterion: Recruitment: Date Mailed */
	$handler->display->display_options['filters']['mailed_date']['id'] = 'mailed_date';
	$handler->display->display_options['filters']['mailed_date']['table'] = 'eve_recruitment';
	$handler->display->display_options['filters']['mailed_date']['field'] = 'mailed_date';
	$handler->display->display_options['filters']['mailed_date']['operator'] = '>=';
	$handler->display->display_options['filters']['mailed_date']['value']['value'] = '-7 days';
	$handler->display->display_options['filters']['mailed_date']['value']['type'] = 'offset';
	/* Filter criterion: Recruitment: Imported */
	$handler->display->display_options['filters']['imported']['id'] = 'imported';
	$handler->display->display_options['filters']['imported']['table'] = 'eve_recruitment';
	$handler->display->display_options['filters']['imported']['field'] = 'imported';
	$handler->display->display_options['filters']['imported']['value'] = '0';
	$handler->display->display_options['displays'] = array(
	  'recruitment_summary' => 'recruitment_summary',
	  'default' => 0,
	);
	$handler->display->display_options['attachment_position'] = 'after';
	$views[$view->name] = $view;
	
	return $views;
}
