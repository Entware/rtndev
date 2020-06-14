#
# Copyright (C) 2017-2020 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# This is the same package as entware-opt, it does not install busybox. It makes several symlinks instead of it!
# /opt/... folder order in /opt/etc/profile is different, /opt folders are the last in PATH
# This package is a replacement of entware-opt for asuswrt firmware


include $(TOPDIR)/rules.mk

PKG_NAME:=entware-upgrade
PKG_VERSION:=1.0
PKG_RELEASE:=1

include $(INCLUDE_DIR)/package.mk

define Package/entware-upgrade
	SECTION:=base
	CATEGORY:=Base system
	TITLE:=Entware upgrade package
	MAINTAINER:=Entware team, https://entware.net
	PKGARCH:=all
endef

define Package/entware-upgrade/description
 Helper package to upgrade Entware for future usage. Currently used to upgrade
 armv7soft (2.3.36) to the new codebase.
endef

define Build/Prepare
endef

define Build/Configure
endef

define Build/Compile
endef

define Package/entware-upgrade/install
	#
endef

ifeq ($(CONFIG_TARGET_armv7soft),y)
define Package/entware-upgrade/postinst
#!/bin/sh
for fw_cmd in sbin/ifconfig sbin/route sbin/ip bin/netstat bin/sh bin/ash; do
    if [ -f /$$fw_cmd ] && [ ! -f /opt/$$fw_cmd ]; then
        ln -s /$$fw_cmd /opt/$$fw_cmd
    fi
done

# now try to create symlinks - it is a std installation
for fw_file in passwd group shells shadow gshadow localtime; do
    [ -f /etc/$$fw_file ] && ln -sf /etc/$$fw_file /opt/etc/$$fw_file
done
endef
else
define Package/entware-upgrade/postinst
#!/bin/sh
echo 'Upgrade operations are not required.'
endef
endif
$(eval $(call BuildPackage,entware-upgrade))
