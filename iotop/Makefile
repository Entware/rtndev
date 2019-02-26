#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=iotop
PKG_VERSION:=0.6
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=http://guichaz.free.fr/iotop/files
PKG_HASH:=3adea2a24eda49bbbaeb4e6ed2042355b441dbd7161e883067a02bfc8dcef75b

include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python-package.mk

#PKG_BUILD_DEPENDS:=python distribute/host

define Package/$(PKG_NAME)
	SUBMENU:=Python
	SECTION:=lang
	CATEGORY:=Languages
	DEPENDS:=+python +python-ncurses
	TITLE:=iotop watches I/O usage information output by the Linux kernel
	URL:=http://guichaz.free.fr/iotop/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/$(PKG_NAME)/description
 Iotop is a Python program with a top like UI used to show of behalf of which process is the I/O going on.
endef


define Build/Compile
	$(call Build/Compile/PyMod,,install --prefix=/opt --root=$(PKG_INSTALL_DIR))
endef

define Package/$(PKG_NAME)/install
	$(INSTALL_DIR) $(1)$(PYTHON_PKG_DIR)
	$(CP) \
	    $(PKG_INSTALL_DIR)$(PYTHON_PKG_DIR)/* \
	    $(1)$(PYTHON_PKG_DIR)/
	$(INSTALL_DIR) $(1)/opt/sbin
	$(CP) $(PKG_INSTALL_DIR)/opt/sbin/iotop $(1)/opt/sbin/iotop
	$(SED) 's!/usr/bin/python!/opt/bin/python!' $(1)/opt/sbin/iotop
endef

$(eval $(call BuildPackage,$(PKG_NAME)))
