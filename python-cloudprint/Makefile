#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=python-cloudprint
PKG_VERSION:=0.14
PKG_RELEASE:=1

PKG_SOURCE:=cloudprint-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://files.pythonhosted.org/packages/1f/ae/eb06181cf118da2a2286e4d288e1e4575e9265b9b5ce514da1b2f5815c18
PKG_HASH:=3b81246d675e0c13fffada7386e6f91e826cb374b57df662f2df72b9fedad237

PKG_BUILD_DIR:=$(BUILD_DIR)/cloudprint-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python-package.mk

define Package/python-cloudprint
	SECTION:=lang
	CATEGORY:=Languages
	SUBMENU:=Python
	DEPENDS:=+python-setuptools +python-cups +python-openssl +python-requests
	TITLE:=Python bindings for the cloudprint API
	URL:=http://cyberelk.net/tim/software/pycloudprint/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/python-cloudprint/description
 This is a Python bindings for the cloudprint API, known as pycloudprint. It was written
 for use with system-config-printer, but can be put to other uses as well.
endef

define Build/Compile
	$(call Build/Compile/PyMod,,install \
		--prefix=/opt \
		--root=$(PKG_INSTALL_DIR) \
	)
endef

define Package/python-cloudprint/install
	$(INSTALL_DIR) $(1)$(PYTHON_PKG_DIR)
	$(CP) \
		$(PKG_INSTALL_DIR)$(PYTHON_PKG_DIR)/* \
		$(1)$(PYTHON_PKG_DIR)
	chmod +x $(1)$(PYTHON_PKG_DIR)/cloudprint/cloudprint.py
	$(INSTALL_DIR) $(1)/opt/{bin,var}
	ln -s $(PYTHON_PKG_DIR)/cloudprint/cloudprint.py \
		$(1)/opt/bin/cloudprint
endef

$(eval $(call BuildPackage,python-cloudprint))
