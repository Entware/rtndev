#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=python-onedrive
PKG_VERSION:=15.10.5
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://files.pythonhosted.org/packages/6f/2b/c419bfe0c90fbfaf3737d2c445edb02977da96a44ba038f54c137fd79d2b
PKG_HASH:=d76f3623eb3063a9f0164f1a4e7bfa23ee4c99db812fb45661d4c4bd84bccef8

include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python-package.mk

define Package/$(PKG_NAME)
	SUBMENU:=Python
	SECTION:=lang
	CATEGORY:=Languages
	TITLE:=Python and CLI interface to MS OneDrive REST API v5.0
	URL:=https://github.com/mk-fg/python-onedrive
	DEPENDS:=+python-requests +python-yaml
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/$(PKG_NAME)/description
 Python and command-line interface for Microsoft LiveConnect OneDrive
 REST API v5.0.
endef

define Build/Compile
	$(call Build/Compile/PyMod,,install \
	    --prefix=/opt \
	    --root="$(PKG_INSTALL_DIR)" \
	)
	$(SED) 's,/usr/bin/env python2,/opt/bin/python,g' \
	    $(PKG_BUILD_DIR)/onedrive/cli_tool.py
endef

define Package/$(PKG_NAME)/install
	$(INSTALL_DIR) $(1)$(PYTHON_PKG_DIR)
	$(CP) \
	    $(PKG_INSTALL_DIR)$(PYTHON_PKG_DIR)/* \
	    $(1)$(PYTHON_PKG_DIR)/
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/onedrive/cli_tool.py $(1)/opt/bin/onedrive-cli
	# fix python exec path in scripts
	find $(PKG_BUILD_DIR) -name *.py | xargs $(SED) 's|/usr/bin/env python2|/opt/bin/python|'
endef

$(eval $(call BuildPackage,$(PKG_NAME)))
