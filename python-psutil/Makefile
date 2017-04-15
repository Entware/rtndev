#
# Copyright (C) 2008-2015 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=python-psutil
PKG_VERSION:=5.2.2
PKG_RELEASE:=1

PKG_SOURCE:=psutil-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://pypi.python.org/packages/57/93/47a2e3befaf194ccc3d05ffbcba2cdcdd22a231100ef7e4cf63f085c900b
PKG_MD5SUM:=bb98d48796cd76d9ccee871aad720f9c

PKG_BUILD_DEPENDS:=python

PKG_UNPACK=$(HOST_TAR) -C $(PKG_BUILD_DIR) --strip-components=1 -xf $(DL_DIR)/$(PKG_SOURCE)

include $(INCLUDE_DIR)/package.mk
$(call include_mk, python-package.mk)

define Package/python-psutil
  SUBMENU:=Python
  SECTION:=lang
  CATEGORY:=Languages
  TITLE:=python-psutil
  URL:=https://github.com/giampaolo/psutil
  DEPENDS:=+python
endef

define Package/python-psutil/description
  psutil is a cross-platform library for retrieving information onrunning processes and system utilization (CPU, memory, disks, network) in Python
endef

define Build/Compile
	$(call Build/Compile/PyMod,,install --prefix=/opt --root=$(PKG_INSTALL_DIR))
endef

define Package/python-psutil/install
	$(INSTALL_DIR) $(1)$(PYTHON_PKG_DIR)
	$(CP) \
	    $(PKG_INSTALL_DIR)$(PYTHON_PKG_DIR)/* \
	    $(1)$(PYTHON_PKG_DIR)
	# fix python exec path in scripts
	find $(PKG_BUILD_DIR) -name *.py | xargs $(SED) 's|/usr/bin/env python|/opt/bin/python|'
endef

$(eval $(call BuildPackage,python-psutil))
