# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2025 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=iotop
PKG_VERSION:=0.6
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=git
PKG_SOURCE_DATE:=2023-04-03
PKG_SOURCE_VERSION:=4b2e1aa2464cfc4a29c9565c9e143b52ef8e4848
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)-$(PKG_SOURCE_DATE).tar.zst
PKG_SOURCE_URL:=https://repo.or.cz/iotop.git
PKG_MIRROR_HASH:=1a4999ff11d781f820cb0de9c19d020781a43df41eb54506cbc6a81a8444b378

PKG_LICENSE:=GPL-2.0-only
PKG_LICENSE_FILES:=COPYING
PKG_MAINTAINER:=Entware team, https://entware.net

include $(TOPDIR)/feeds/packages/lang/python/pypi.mk
include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python3-package.mk

define Package/python3-iotop
  SECTION:=admin
  CATEGORY:=Administration
  TITLE:=watches I/O usage information output by the Linux kernel
  URL:=http://guichaz.free.fr/iotop/
  DEPENDS:=+python3-ctypes +python3-ncurses
endef

define Package/python3-iotop/description
 Iotop is a Python program with a top like UI used to show of behalf of
 which process is the I/O going on.
endef

define Package/python3-iotop/install
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/iotop $(1)/opt/sbin
	$(INSTALL_DIR) $(1)$(PYTHON3_PKG_DIR)
	$(CP) $(PKG_INSTALL_DIR)$(PYTHON3_PKG_DIR)/* $(1)$(PYTHON3_PKG_DIR)
	$(call Python3/FixShebang,$(1)/opt/sbin/iotop)
endef

define Package/python3-iotop/postrm
#!/bin/sh

rm -rf $(PYTHON3_PKG_DIR)/$(PYPI_NAME)
rm -rf $(PYTHON3_PKG_DIR)/$(PYPI_NAME)-$(PKG_VERSION).dist-info
endef

$(eval $(call Py3Package,python3-iotop))
$(eval $(call BuildPackage,python3-iotop))
