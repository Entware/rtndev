#
# Copyright (C) 2011-2014 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=python-werkzeug
PKG_VERSION:=0.11.2
PKG_RELEASE:=1

PKG_SOURCE:=Werkzeug-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://pypi.python.org/packages/source/W/Werkzeug
PKG_MD5SUM:=b3b90c940ab5f77a1e96313263c6d288

PKG_BUILD_DIR:=$(BUILD_DIR)/Werkzeug-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk
$(call include_mk, python-package.mk)

define Package/python-werkzeug
	SECTION:=lang
	CATEGORY:=Languages
	SUBMENU:=Python
	DEPENDS:=+python
	TITLE:=python utilities for WSGI applications
	URL:=http://werkzeug.pocoo.org/
	MAINTAINER:=Entware team, entware.wl500g.info
endef

define Package/python-werkzeug/description
 Werkzeug started as simple collection of various utilities for WSGI
 applications and has become one of the most advanced WSGI utility modules.
endef

define Build/Compile
	$(call Build/Compile/PyMod,,install --prefix=/opt --root=$(PKG_INSTALL_DIR))
endef

define Package/python-werkzeug/install
	$(INSTALL_DIR) $(1)$(PYTHON_PKG_DIR)
	$(CP) \
		$(PKG_INSTALL_DIR)$(PYTHON_PKG_DIR)/* \
		$(1)$(PYTHON_PKG_DIR)
endef

$(eval $(call BuildPackage,python-werkzeug))
