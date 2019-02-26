#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Used by weave-minimal only

include $(TOPDIR)/rules.mk

PKG_NAME:=python-werkzeug
PKG_VERSION:=0.14.1
PKG_RELEASE:=1

PKG_SOURCE:=Werkzeug-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://files.pythonhosted.org/packages/9f/08/a3bb1c045ec602dc680906fc0261c267bed6b3bb4609430aff92c3888ec8
PKG_HASH:=c3fd7a7d41976d9f44db327260e263132466836cef6f91512889ed60ad26557c

PKG_BUILD_DIR:=$(BUILD_DIR)/Werkzeug-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python-package.mk

define Package/python-werkzeug
	SECTION:=lang
	CATEGORY:=Languages
	SUBMENU:=Python
	DEPENDS:=+python
	TITLE:=python utilities for WSGI applications
	URL:=http://werkzeug.pocoo.org/
	MAINTAINER:=Entware team, https://entware.net
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
